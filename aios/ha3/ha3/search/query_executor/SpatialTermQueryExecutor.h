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

#include <stddef.h>
#include <stdint.h>
#include <string>

#include "autil/Log.h" // IWYU pragma: keep
#include "ha3/search/TermQueryExecutor.h"
#include "indexlib/index/common/ErrorCode.h"
#include "indexlib/index/inverted_index/DocValueFilter.h"
#include "indexlib/indexlib.h"
#include "indexlib/misc/common.h"

namespace indexlib {
namespace index {
class PostingIterator;
class SpatialPostingIterator;
} // namespace index
} // namespace indexlib
namespace isearch {
namespace common {
class Term;
} // namespace common
} // namespace isearch

namespace isearch {
namespace search {

class SpatialTermQueryExecutor : public TermQueryExecutor {
public:
    SpatialTermQueryExecutor(indexlib::index::PostingIterator *iter, const common::Term &term);
    ~SpatialTermQueryExecutor();

private:
    SpatialTermQueryExecutor(const SpatialTermQueryExecutor &);
    SpatialTermQueryExecutor &operator=(const SpatialTermQueryExecutor &);

public:
    const std::string getName() const override {
        return "SpatialTermQueryExecutor";
    }
    indexlib::index::ErrorCode doSeek(docid_t id, docid_t &result) override;
    uint32_t getSeekDocCount() override;

    void reset() override {
        TermQueryExecutor::reset();
        initSpatialPostingIterator();
    }

    /* override */ indexlib::index::DocValueFilter *stealFilter() override {
        indexlib::index::DocValueFilter *tmp = _filter;
        _filter = NULL;
        return tmp;
    }

private:
    void initSpatialPostingIterator();

private:
    indexlib::index::SpatialPostingIterator *_spatialIter;
    indexlib::index::DocValueFilter *_filter;
    int64_t _testDocCount;

private:
    AUTIL_LOG_DECLARE();
};

typedef std::shared_ptr<SpatialTermQueryExecutor> SpatialTermQueryExecutorPtr;

} // namespace search
} // namespace isearch
