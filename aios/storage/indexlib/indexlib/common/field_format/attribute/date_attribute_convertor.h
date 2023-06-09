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
#ifndef __INDEXLIB_DATE_ATTRIBUTE_CONVERTOR_H
#define __INDEXLIB_DATE_ATTRIBUTE_CONVERTOR_H

#include <memory>

#include "indexlib/common/field_format/attribute/single_value_attribute_convertor.h"
#include "indexlib/common_define.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace common {

class DateAttributeConvertor : public SingleValueAttributeConvertor<uint32_t>
{
public:
    DateAttributeConvertor(bool needHash, const std::string& fieldName);
    ~DateAttributeConvertor();

public:
    autil::StringView InnerEncode(const autil::StringView& attrData, autil::mem_pool::Pool* memPool,
                                  std::string& strResult, char* outBuffer, EncodeStatus& status) override;

private:
    bool ParseDate(const autil::StringView& attrData, uint32_t& year, uint32_t& month, uint32_t& day) const;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(DateAttributeConvertor);
}} // namespace indexlib::common

#endif //__INDEXLIB_DATE_ATTRIBUTE_CONVERTOR_H
