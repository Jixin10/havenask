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

#include "indexlib/common_define.h"
#include "indexlib/config/kv_index_config.h"
#include "indexlib/document/kv_document/kv_index_document.h"
#include "indexlib/indexlib.h"

DECLARE_REFERENCE_CLASS(document, NormalDocument);

namespace indexlib { namespace document {

class KVKeyExtractor
{
public:
    KVKeyExtractor(const config::KVIndexConfigPtr& kvConfig)
        : _regionId(kvConfig->GetRegionCount() > 1 ? kvConfig->GetRegionId() : INVALID_REGIONID)
        , _fieldType(kvConfig->GetFieldConfig()->GetFieldType())
        , _useNumberHash(kvConfig->UseNumberHash())
    {
    }

    ~KVKeyExtractor() {}

public:
    bool GetKey(document::KVIndexDocument* doc, uint64_t& key);
    void HashKey(const std::string& key, uint64_t& keyHash);

private:
    regionid_t _regionId;
    FieldType _fieldType;
    bool _useNumberHash;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(KVKeyExtractor);
}} // namespace indexlib::document
