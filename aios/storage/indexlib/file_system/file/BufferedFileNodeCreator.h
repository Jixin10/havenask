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
#include <string>

#include "autil/Log.h"
#include "indexlib/file_system/FileSystemDefine.h"
#include "indexlib/file_system/file/FileNode.h"
#include "indexlib/file_system/file/FileNodeCreator.h"
#include "indexlib/file_system/file/SessionFileCache.h"
#include "indexlib/util/memory_control/BlockMemoryQuotaController.h"

namespace indexlib { namespace file_system {
class LoadConfig;
}} // namespace indexlib::file_system

namespace indexlib { namespace file_system {

class BufferedFileNodeCreator : public FileNodeCreator
{
public:
    BufferedFileNodeCreator(SessionFileCachePtr fileCache = SessionFileCachePtr());
    ~BufferedFileNodeCreator();

public:
    bool Init(const LoadConfig& loadConfig, const util::BlockMemoryQuotaControllerPtr& memController) override;
    std::shared_ptr<FileNode> CreateFileNode(FSOpenType type, bool readOnly, const std::string& linkRoot) override;
    bool Match(const std::string& filePath, const std::string& lifecycle) const override;
    bool MatchType(FSOpenType type) const override;
    size_t EstimateFileLockMemoryUse(size_t fileLength) const noexcept override;
    FSOpenType GetDefaultOpenType() const override { return FSOT_BUFFERED; }

private:
    SessionFileCachePtr _fileCache;

private:
    AUTIL_LOG_DECLARE();
};

typedef std::shared_ptr<BufferedFileNodeCreator> BufferedFileNodeCreatorPtr;
}} // namespace indexlib::file_system
