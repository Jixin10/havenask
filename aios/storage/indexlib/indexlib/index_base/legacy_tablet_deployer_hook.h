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
#ifndef __INDEXLIB_LEGACY_TABLET_DEPLOYER_HOOK_H
#define __INDEXLIB_LEGACY_TABLET_DEPLOYER_HOOK_H

#include "indexlib/framework/hooks/ITabletDeployerHook.h"

namespace indexlib { namespace index_base {

class LegacyTabletDeployerHook final : public framework::ITabletDeployerHook
{
public:
    std::unique_ptr<framework::ITabletDeployerHook> Create() const override;
    void RewriteLoadConfigList(const std::string& rootPath, const indexlibv2::config::TabletOptions& tabletOptions,
                               versionid_t versionId, const std::string& localPath, const std::string& remotePath,
                               file_system::LoadConfigList* loadConfigList) override;
};

}} // namespace indexlib::index_base

#endif //__INDEXLIB_LEGACY_TABLET_DEPLOYER_HOOK_H
