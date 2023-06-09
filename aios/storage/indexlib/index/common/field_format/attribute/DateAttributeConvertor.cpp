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
#include "indexlib/index/common/field_format/attribute/DateAttributeConvertor.h"

#include "indexlib/util/TimestampUtil.h"

namespace indexlibv2::index {
AUTIL_LOG_SETUP(indexlib.index, DateAttributeConvertor);

DateAttributeConvertor::DateAttributeConvertor(bool needHash, const std::string& fieldName)
    : SingleValueAttributeConvertor<uint32_t>(needHash, fieldName)
{
}

autil::StringView DateAttributeConvertor::InnerEncode(const autil::StringView& attrData, autil::mem_pool::Pool* memPool,
                                                      std::string& strResult, char* outBuffer, EncodeStatus& status)
{
    assert(_needHash == false);
    uint32_t* value = (uint32_t*)Allocate(memPool, strResult, outBuffer, sizeof(uint32_t));

    uint64_t timestamp;
    if (!indexlib::util::TimestampUtil::ConvertToTimestamp(ft_date, attrData, timestamp, 0)) {
        status = EncodeStatus::ES_TYPE_ERROR;
        *value = uint64_t();
        AUTIL_LOG(DEBUG, "convert attribute [%s] invalid date format [%s].", _fieldName.c_str(), attrData.data());
        ERROR_COLLECTOR_LOG(ERROR, "convert attribute [%s] invalid date format [%s].", _fieldName.c_str(),
                            attrData.data());
    } else {
        // day idx from 1970-01-01
        *value = (uint32_t)(timestamp / indexlib::util::TimestampUtil::DAY_MILLION_SEC);
    }
    return autil::StringView((char*)value, sizeof(uint32_t));
}
} // namespace indexlibv2::index
