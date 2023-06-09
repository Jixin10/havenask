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

#include <memory>

#include "indexlib/index/inverted_index/truncate/TruncateMetaReader.h"

namespace indexlib::index {

class TimeStrategyTruncateMetaReader : public TruncateMetaReader
{
public:
    TimeStrategyTruncateMetaReader(int64_t minTime, int64_t maxTime, bool desc);
    ~TimeStrategyTruncateMetaReader() = default;

public:
    virtual bool Lookup(const index::DictKeyInfo& key, int64_t& min, int64_t& max) const override;

private:
    int64_t _minTime;
    int64_t _maxTime;

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlib::index
