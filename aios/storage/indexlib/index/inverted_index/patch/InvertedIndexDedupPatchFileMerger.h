/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "autil/Log.h"
#include "indexlib/index/common/patch/PatchFileMerger.h"
#include "indexlib/index/inverted_index/config/InvertedIndexConfig.h"

namespace indexlib::index {

class InvertedIndexDedupPatchFileMerger : public indexlibv2::index::PatchFileMerger
{
public:
    InvertedIndexDedupPatchFileMerger(
        const std::shared_ptr<indexlibv2::config::InvertedIndexConfig>& invertedIndexConfig,
        const indexlibv2::index::PatchInfos& allPatchInfos)
        : PatchFileMerger(allPatchInfos)
        , _invertedIndexConfig(invertedIndexConfig)
    {
    }
    ~InvertedIndexDedupPatchFileMerger() = default;

private:
    std::shared_ptr<indexlibv2::index::PatchMerger> CreatePatchMerger(segmentid_t) const override;

    Status FindPatchFiles(const indexlibv2::index::IIndexMerger::SegmentMergeInfos& segMergeInfos,
                          indexlibv2::index::PatchInfos* patchInfos) override;

private:
    std::shared_ptr<indexlibv2::config::InvertedIndexConfig> _invertedIndexConfig;

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlib::index
