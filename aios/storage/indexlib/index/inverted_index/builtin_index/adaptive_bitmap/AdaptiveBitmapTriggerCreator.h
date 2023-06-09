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

namespace indexlibv2::config {
class InvertedIndexConfig;
}
namespace indexlibv2::index {
class DocMapper;
}

namespace indexlib::index {

class AdaptiveBitmapTrigger;

class AdaptiveBitmapTriggerCreator
{
public:
    AdaptiveBitmapTriggerCreator(const std::shared_ptr<indexlibv2::index::DocMapper>& docMapper);
    ~AdaptiveBitmapTriggerCreator() = default;

    std::shared_ptr<AdaptiveBitmapTrigger>
    Create(const std::shared_ptr<indexlibv2::config::InvertedIndexConfig>& indexConf);

private:
    std::shared_ptr<indexlibv2::index::DocMapper> _docMapper;

    AUTIL_LOG_DECLARE();
};

} // namespace indexlib::index
