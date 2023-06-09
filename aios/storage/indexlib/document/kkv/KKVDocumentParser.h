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

#include "indexlib/document/kkv/KKVKeysExtractor.h"
#include "indexlib/document/kv/KVDocumentParser.h"

namespace indexlibv2::config {
class KKVIndexConfig;
}

namespace indexlibv2::document {

class KKVDocumentParser final : public KVDocumentParser
{
public:
    KKVDocumentParser();
    ~KKVDocumentParser();

private:
    std::unique_ptr<KVIndexDocumentParserBase>
    CreateIndexFieldsParser(const std::shared_ptr<config::IIndexConfig>& indexConfig) const override;

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlibv2::document
