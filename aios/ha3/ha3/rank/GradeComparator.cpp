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
#include "ha3/rank/GradeComparator.h"

#include "matchdoc/MatchDoc.h"
#include "matchdoc/Reference.h"

#include "ha3/rank/DistinctInfo.h"
#include "autil/Log.h"

namespace isearch {
namespace rank {
AUTIL_LOG_SETUP(ha3, GradeComparator);

GradeComparator::GradeComparator(
        matchdoc::Reference<DistinctInfo> *distInfoRef, bool flag)
{
    _distInfoRef = distInfoRef;
    _flag = flag;
}

GradeComparator::~GradeComparator() {
}
bool GradeComparator::compare(matchdoc::MatchDoc a, matchdoc::MatchDoc b) const {
    if (_flag) {
        return _distInfoRef->getReference(b).getGradeBoost()
            < _distInfoRef->getReference(a).getGradeBoost();
    } else {
        return _distInfoRef->getReference(a).getGradeBoost()
            < _distInfoRef->getReference(b).getGradeBoost();
    }
}

} // namespace rank
} // namespace isearch
