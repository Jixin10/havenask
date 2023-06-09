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

#include "indexlib/file_system/FileSystemDefine.h"
#include "indexlib/index/common/FSWriterParamDecider.h"

namespace indexlib { namespace index {

class DefaultFSWriterParamDecider : public FSWriterParamDecider
{
public:
    DefaultFSWriterParamDecider() = default;
    ~DefaultFSWriterParamDecider() = default;

public:
    file_system::WriterOption MakeParam(const std::string& fileName) override { return file_system::WriterOption(); }
};
}} // namespace indexlib::index
