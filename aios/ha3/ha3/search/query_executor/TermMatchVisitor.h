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

#include "ha3/common/ModifyQueryVisitor.h"
#include "indexlib/config/ITabletSchema.h"

namespace isearch {
namespace common {
class Query;
class AndNotQuery;
class AndQuery;
class MultiTermQuery;
class NumberQuery;
class OrQuery;
class PhraseQuery;
class RankQuery;
class TermQuery;
}  // namespace common
}  // namespace isearch

namespace isearch {
namespace search {

class TermMatchVisitor : public isearch::common::ModifyQueryVisitor
{
public:
    TermMatchVisitor(const std::shared_ptr<indexlibv2::config::ITabletSchema> &indexSchemaPtr);
    ~TermMatchVisitor() {}
private:
    TermMatchVisitor(const TermMatchVisitor &);
    TermMatchVisitor & operator=(const TermMatchVisitor &);
public:
    void visitTermQuery(isearch::common::TermQuery *query) override;
    void visitPhraseQuery(isearch::common::PhraseQuery *query) override;
    void visitAndQuery(isearch::common::AndQuery *query) override;
    void visitOrQuery(isearch::common::OrQuery *query) override;
    void visitAndNotQuery(isearch::common::AndNotQuery *query) override;
    void visitRankQuery(isearch::common::RankQuery *query) override;
    void visitNumberQuery(isearch::common::NumberQuery *query) override;
    void visitMultiTermQuery(isearch::common::MultiTermQuery *query) override;
    void visitMidQuery(isearch::common::Query *query);
    void visitLeafQuery(const std::string &indexName, isearch::common::Query *query);
private:

    const std::shared_ptr<indexlibv2::config::ITabletSchema> &_indexSchemaPtr;
    AUTIL_LOG_DECLARE();
};

} // namespace rank
} // namespace isearch
