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

#include "build_service/workflow/RealtimeBuilderDefine.h"

namespace indexlibv2::framework {
class ITablet;
} // namespace indexlibv2::framework

namespace build_service::util {
class SwiftClientCreator;
} // namespace build_service::util

namespace isearch {
namespace sql {

struct TabletWaiterInitOption {
    int32_t from;
    int32_t to;
    std::shared_ptr<indexlibv2::framework::ITablet> tablet;
    std::shared_ptr<build_service::util::SwiftClientCreator> swiftClientCreator;
    build_service::workflow::RealtimeInfoWrapper realtimeInfo;
};

} // namespace sql
} // namespace isearch
