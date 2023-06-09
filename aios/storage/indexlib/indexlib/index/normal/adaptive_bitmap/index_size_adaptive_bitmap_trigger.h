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
#ifndef __INDEXLIB_INDEX_SIZE_ADAPTIVE_BITMAP_TRIGGER_H
#define __INDEXLIB_INDEX_SIZE_ADAPTIVE_BITMAP_TRIGGER_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/index/normal/adaptive_bitmap/adaptive_bitmap_trigger.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace index { namespace legacy {

class IndexSizeAdaptiveBitmapTrigger : public AdaptiveBitmapTrigger
{
public:
    IndexSizeAdaptiveBitmapTrigger(uint32_t totalDocCount);
    ~IndexSizeAdaptiveBitmapTrigger();

public:
    bool MatchAdaptiveBitmap(const PostingMergerPtr& postingMerger) override;

private:
    uint32_t mEstimateBitmapSize;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(IndexSizeAdaptiveBitmapTrigger);
}}} // namespace indexlib::index::legacy

#endif //__INDEXLIB_INDEX_SIZE_ADAPTIVE_BITMAP_TRIGGER_H
