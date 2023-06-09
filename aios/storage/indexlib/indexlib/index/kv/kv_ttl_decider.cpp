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
#include "indexlib/index/kv/kv_ttl_decider.h"

#include "indexlib/config/kv_index_config.h"

using namespace std;
using namespace indexlib::config;

namespace indexlib { namespace index {
IE_LOG_SETUP(index, KVTTLDecider);

KVTTLDecider::KVTTLDecider() {}

KVTTLDecider::~KVTTLDecider() {}

void KVTTLDecider::Init(const IndexPartitionSchemaPtr& schema)
{
    mTTLVec.reserve(schema->GetRegionCount());
    for (regionid_t id = 0; id < (regionid_t)schema->GetRegionCount(); id++) {
        KVIndexConfigPtr kvConfig =
            DYNAMIC_POINTER_CAST(KVIndexConfig, schema->GetIndexSchema(id)->GetPrimaryKeyIndexConfig());
        assert(kvConfig);
        mTTLVec.emplace_back(schema->TTLEnabled(id), kvConfig->GetTTL());
    }
}
}} // namespace indexlib::index
