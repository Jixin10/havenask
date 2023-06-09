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
#include "indexlib/framework/TabletReader.h"

namespace indexlibv2::table {

class AggregationTabletReader : public framework::TabletReader
{
public:
    AggregationTabletReader(const std::shared_ptr<config::TabletSchema>& schema);
    ~AggregationTabletReader();

public:
    Status Open(const std::shared_ptr<framework::TabletData>& tabletData,
                const framework::ReadResource& readResource) override;

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlibv2::table
