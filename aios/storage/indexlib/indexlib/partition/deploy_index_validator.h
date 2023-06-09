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
#ifndef __INDEXLIB_DEPLOY_INDEX_VALIDATOR_H
#define __INDEXLIB_DEPLOY_INDEX_VALIDATOR_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/indexlib.h"

DECLARE_REFERENCE_CLASS(file_system, Directory);
DECLARE_REFERENCE_CLASS(index_base, Version);

namespace indexlib { namespace partition {

class DeployIndexValidator
{
public:
    DeployIndexValidator() {};
    ~DeployIndexValidator() {};

public:
    static void ValidateDeploySegments(const file_system::DirectoryPtr& rootDir, const index_base::Version& version);

private:
    static void ValidateSingleSegmentDeployFiles(const file_system::DirectoryPtr& segDir);
    static void ValidatePartitionPatchSegmentDeployFiles(const file_system::DirectoryPtr& rootDir,
                                                         const index_base::Version& version);

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(DeployIndexValidator);
}} // namespace indexlib::partition

#endif //__INDEXLIB_DEPLOY_INDEX_VALIDATOR_H
