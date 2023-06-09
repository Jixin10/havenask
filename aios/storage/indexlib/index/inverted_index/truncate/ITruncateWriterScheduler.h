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
#include "autil/WorkItem.h"
#include "indexlib/base/Status.h"

namespace indexlib::index {

class ITruncateWriterScheduler
{
public:
    ITruncateWriterScheduler() = default;
    virtual ~ITruncateWriterScheduler() = default;

public:
    virtual Status PushWorkItem(autil::WorkItem* workItem) = 0;
    virtual Status WaitFinished() = 0;

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlib::index