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
#ifndef __INDEXLIB_JOIN_DOCID_READER_BASE_H
#define __INDEXLIB_JOIN_DOCID_READER_BASE_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace partition {

class JoinDocidReaderBase
{
public:
    JoinDocidReaderBase() {}
    virtual ~JoinDocidReaderBase() {}

public:
    virtual docid_t GetAuxDocid(docid_t mainDocid) = 0;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(JoinDocidReaderBase);
}} // namespace indexlib::partition

#endif //__INDEXLIB_JOIN_DOCID_READER_BASE_H
