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
#ifndef __INDEXLIB_TEMPERATURE_LAYER_CONFIG_H
#define __INDEXLIB_TEMPERATURE_LAYER_CONFIG_H

#include <memory>

#include "autil/legacy/jsonizable.h"
#include "indexlib/common_define.h"
#include "indexlib/config/attribute_schema.h"
#include "indexlib/config/temperature_condition.h"

DECLARE_REFERENCE_CLASS(config, TemperatureLayerConfigImpl);

namespace indexlib { namespace config {

class TemperatureLayerConfig : public autil::legacy::Jsonizable
{
public:
    TemperatureLayerConfig();
    ~TemperatureLayerConfig();

public:
    void Jsonize(autil::legacy::Jsonizable::JsonWrapper& json) override;
    void Check(const AttributeSchemaPtr& attributeSchema) const;
    const std::vector<TemperatureConditionPtr>& GetConditions() const;
    const std::string GetDefaultProperty() const;
    void AssertEqual(const TemperatureLayerConfig& other) const;

public:
    bool operator==(const TemperatureLayerConfig& other) const;
    bool operator!=(const TemperatureLayerConfig& other) const { return !(*this == other); }

private:
    TemperatureLayerConfigImplPtr mImpl;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(TemperatureLayerConfig);
}} // namespace indexlib::config

#endif //__INDEXLIB_TEMPERATURE_LAYER_CONFIG_H
