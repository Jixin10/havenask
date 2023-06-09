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
#ifndef __INDEXLIB_OFFLINE_CONFIG_IMPL_H
#define __INDEXLIB_OFFLINE_CONFIG_IMPL_H

#include <memory>

#include "autil/legacy/jsonizable.h"
#include "indexlib/common_define.h"
#include "indexlib/config/load_config_list.h"
#include "indexlib/config/module_info.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace config {

class OfflineConfigImpl : public autil::legacy::Jsonizable
{
public:
    OfflineConfigImpl();
    OfflineConfigImpl(const OfflineConfigImpl& other);
    ~OfflineConfigImpl();

public:
    void Jsonize(autil::legacy::Jsonizable::JsonWrapper& json) override;
    void Check() const;
    void operator=(const OfflineConfigImpl& other);
    void RebuildTruncateIndex() { mNeedRebuildTruncateIndex = true; }
    void RebuildAdaptiveBitmap() { mNeedRebuildAdaptiveBitmap = true; }
    bool NeedRebuildTruncateIndex() const { return mNeedRebuildTruncateIndex; }
    bool NeedRebuildAdaptiveBitmap() const { return mNeedRebuildAdaptiveBitmap; }
    const LoadConfigList& GetLoadConfigList() const { return mLoadConfigList; }
    void SetLoadConfigList(const LoadConfigList& loadConfigList);

    const ModuleInfos& GetModuleInfos() const { return mModuleInfos; }

private:
    // TODO: add new config
    bool mNeedRebuildAdaptiveBitmap;
    bool mNeedRebuildTruncateIndex;
    LoadConfigList mLoadConfigList;
    ModuleInfos mModuleInfos;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(OfflineConfigImpl);
}} // namespace indexlib::config

#endif //__INDEXLIB_OFFLINE_CONFIG_IMPL_H
