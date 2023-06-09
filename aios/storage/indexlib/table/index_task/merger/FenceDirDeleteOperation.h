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
#include "indexlib/base/Status.h"
#include "indexlib/file_system/Directory.h"
#include "indexlib/framework/index_task/IndexOperation.h"
#include "indexlib/framework/index_task/IndexOperationDescription.h"

namespace indexlib::index_base {
struct SegmentInfo;
}

namespace indexlibv2::table {

class FenceDirDeleteOperation : public framework::IndexOperation
{
public:
    FenceDirDeleteOperation(const framework::IndexOperationDescription& opDesc);
    ~FenceDirDeleteOperation();

    static framework::IndexOperationDescription CreateOperationDescription(framework::IndexOperationId id);

    Status Execute(const framework::IndexTaskContext& context) override;

public:
    static constexpr char OPERATION_TYPE[] = "fence_dir_delete";

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlibv2::table
