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

#include "indexlib/document/normal/Field.h"

namespace indexlib { namespace document {

class NullField : public Field
{
public:
    NullField(autil::mem_pool::Pool* pool = NULL);
    ;
    ~NullField();

public:
    void Reset() override;
    void serialize(autil::DataBuffer& dataBuffer) const override;
    void deserialize(autil::DataBuffer& dataBuffer) override;
    bool operator==(const Field& field) const override;
    bool operator!=(const Field& field) const override { return !(*this == field); }

private:
    AUTIL_LOG_DECLARE();
};

}} // namespace indexlib::document
