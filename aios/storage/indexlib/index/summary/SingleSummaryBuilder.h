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
#include <map>
#include <string>
#include <vector>

#include "autil/Log.h"
#include "autil/NoCopyable.h"
#include "indexlib/base/Status.h"
#include "indexlib/base/Types.h"
#include "indexlib/document/IDocument.h"
#include "indexlib/framework/TabletData.h"

namespace indexlibv2::config {
class IIndexConfig;
class SummaryIndexConfig;
} // namespace indexlibv2::config

namespace indexlibv2::index {
class SummaryMemIndexer;
} // namespace indexlibv2::index

namespace indexlib::index {
class SingleSummaryBuilder : public autil::NoCopyable
{
public:
    SingleSummaryBuilder();
    ~SingleSummaryBuilder();

public:
    Status Init(const indexlibv2::framework::TabletData& tabletData,
                const std::shared_ptr<indexlibv2::config::IIndexConfig>& indexConfig);

public:
    Status AddDocument(indexlibv2::document::IDocument* doc);

    const std::shared_ptr<indexlibv2::config::SummaryIndexConfig>& GetSummaryIndexConfig() const;

private:
    indexlibv2::index::SummaryMemIndexer* _buildingIndexer = nullptr;
    std::shared_ptr<indexlibv2::config::SummaryIndexConfig> _summaryIndexConfig = nullptr;

    AUTIL_LOG_DECLARE();
};

} // namespace indexlib::index
