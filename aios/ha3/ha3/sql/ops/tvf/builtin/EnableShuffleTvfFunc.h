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

#include "ha3/sql/common/Log.h" // IWYU pragma: keep
#include "ha3/sql/ops/tvf/TvfFunc.h"
#include "ha3/sql/ops/tvf/TvfFuncCreatorR.h"
#include "navi/builder/ResourceDefBuilder.h"
#include "table/Table.h"

namespace isearch {
namespace sql {
class SqlTvfProfileInfo;
} // namespace sql
} // namespace isearch

namespace isearch {
namespace sql {

class EnableShuffleTvfFunc : public TvfFunc {
public:
    EnableShuffleTvfFunc();
    ~EnableShuffleTvfFunc();
    EnableShuffleTvfFunc(const EnableShuffleTvfFunc &) = delete;
    EnableShuffleTvfFunc &operator=(const EnableShuffleTvfFunc &) = delete;

private:
    bool init(TvfFuncInitContext &context) override;
    bool compute(const table::TablePtr &input, bool eof, table::TablePtr &output) override;
};

typedef std::shared_ptr<EnableShuffleTvfFunc> EnableShuffleTvfFuncPtr;

class EnableShuffleTvfFuncCreator : public TvfFuncCreatorR {
public:
    EnableShuffleTvfFuncCreator();
    ~EnableShuffleTvfFuncCreator();

public:
    void def(navi::ResourceDefBuilder &builder) const override {
        builder.name("ENABLE_SHUFFLE_TVF_FUNC");
    }

private:
    EnableShuffleTvfFuncCreator(const EnableShuffleTvfFuncCreator &) = delete;
    EnableShuffleTvfFuncCreator &operator=(const EnableShuffleTvfFuncCreator &) = delete;

private:
    TvfFunc *createFunction(const SqlTvfProfileInfo &info) override;
};
typedef std::shared_ptr<EnableShuffleTvfFuncCreator> EnableShuffleTvfFuncCreatorPtr;
} // namespace sql
} // namespace isearch
