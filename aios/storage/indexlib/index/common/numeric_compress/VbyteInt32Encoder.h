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

#include "indexlib/index/common/numeric_compress/IntEncoder.h"

namespace indexlib::index {

class VbyteInt32Encoder : public Int32Encoder
{
public:
    VbyteInt32Encoder();
    ~VbyteInt32Encoder();

public:
    std::pair<Status, uint32_t> Encode(file_system::ByteSliceWriter& sliceWriter, const uint32_t* src,
                                       uint32_t srcLen) const override;

    std::pair<Status, uint32_t> Encode(uint8_t* dest, const uint32_t* src, uint32_t srcLen) const override;

    std::pair<Status, uint32_t> Decode(uint32_t* dest, uint32_t destLen,
                                       file_system::ByteSliceReader& sliceReader) const override;

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlib::index
