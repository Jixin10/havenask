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
#include "indexlib/base/Status.h"
#include "indexlib/base/Types.h"

namespace indexlibv2::config {
class KVIndexConfig;
}

namespace indexlibv2::framework {
class Segment;
}

namespace indexlibv2::index {

class AdapterIgnoreFieldCalculator;
class IKVSegmentReader;
class IKVIterator;

class KVSegmentReaderCreator
{
public:
    static std::pair<Status, std::unique_ptr<IKVIterator>>
    CreateIterator(const std::shared_ptr<framework::Segment>& segment,
                   const std::shared_ptr<config::KVIndexConfig>& indexConfig, schemaid_t schemaId,
                   const std::shared_ptr<AdapterIgnoreFieldCalculator>& ignoreFieldCalculator,
                   bool disablePlainFormat = false);

    static std::pair<Status, std::shared_ptr<IKVSegmentReader>>
    CreateSegmentReader(const std::shared_ptr<IKVSegmentReader>& segReader,
                        const std::shared_ptr<config::KVIndexConfig>& segmentIndexConfig,
                        const std::shared_ptr<config::KVIndexConfig>& readerIndexConfig,
                        const std::vector<std::string>& ignoreFields, bool disablePlainFormat);

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlibv2::index
