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

#include "autil/Log.h"
#include "indexlib/base/Status.h"
#include "indexlib/file_system/ErrorCode.h"
#include "indexlib/framework/Fence.h"
#include "indexlib/framework/Version.h"

namespace indexlib::file_system {
class Directory;
}

namespace indexlibv2::framework {

// commit only means write version file to fence dir, publish means write to root path
class VersionCommitter
{
public:
    static Status Commit(const Version& version,
                         const std::shared_ptr<indexlib::file_system::Directory>& fenceDirectory,
                         const std::vector<std::string>& filteredDirs);

    static Status Commit(const Version& version, const Fence& fence, const std::vector<std::string>& filteredDirs);

    static Status CommitAndPublish(const Version& version, const Fence& fence,
                                   const std::vector<std::string>& filteredDirs);

private:
    static std::string GetVersionFileName(versionid_t versionId);
    static void FillWishList(const Version& version, std::vector<std::string>* wishFileList,
                             std::vector<std::string>* wishDirList);
    static indexlib::file_system::ErrorCode PublishVersion(const Version& version, const std::string& globalRoot,
                                                           const std::string& tempIdentifier);

    AUTIL_LOG_DECLARE();
};

} // namespace indexlibv2::framework
