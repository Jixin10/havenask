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

#include "autil/Log.h"
#include "ha3/sql/ops/scan/ScanBase.h"
#include "table/Table.h"

namespace isearch {
namespace sql {

class LogicalScan : public ScanBase {
public:
    LogicalScan(const ScanInitParam &param);
    virtual ~LogicalScan();

private:
    LogicalScan(const LogicalScan &);
    LogicalScan &operator=(const LogicalScan &);

public:
    bool doBatchScan(table::TablePtr &table, bool &eof) override;

private:
    bool doInit() override;
    table::TablePtr createTable();

private:
    AUTIL_LOG_DECLARE();
};

typedef std::shared_ptr<LogicalScan> LogicalScanPtr;
} // namespace sql
} // namespace isearch
