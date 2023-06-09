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

#include <stdint.h>

#include "ha3/isearch.h"
#include "autil/Log.h" // IWYU pragma: keep

namespace isearch {
namespace rank {

class DistinctBoostScorer
{
public:
    DistinctBoostScorer(){}
    virtual ~DistinctBoostScorer(){}
public:
    virtual score_t calculateBoost(uint32_t keyPos, score_t rawScore) = 0;
};

} // namespace rank
} // namespace isearch

