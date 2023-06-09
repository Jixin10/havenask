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
#include "indexlib/table/normal_table/virtual_attribute/VirtualAttributeBuildWorkItem.h"

#include "indexlib/table/normal_table/virtual_attribute/SingleVirtualAttributeBuilder.h"

namespace indexlib::table {
AUTIL_LOG_SETUP(indexlib.table, VirtualAttributeBuildWorkItem);

VirtualAttributeBuildWorkItem::VirtualAttributeBuildWorkItem(SingleVirtualAttributeBuilder* builder,
                                                             indexlibv2::document::IDocumentBatch* documentBatch)
    : AttributeBuildWorkItem<indexlibv2::table::VirtualAttributeDiskIndexer,
                             indexlibv2::table::VirtualAttributeMemIndexer>(builder, documentBatch)
{
}

VirtualAttributeBuildWorkItem::~VirtualAttributeBuildWorkItem() {}

} // namespace indexlib::table
