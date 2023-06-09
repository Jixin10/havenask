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
#include "indexlib/index/inverted_index/builtin_index/bitmap/BitmapInDocPositionState.h"

#include "indexlib/index/inverted_index/builtin_index/bitmap/BitmapInDocPositionIterator.h"

namespace indexlib::index {

AUTIL_LOG_SETUP(indexlib.index, BitmapInDocPositionState);

BitmapInDocPositionState::BitmapInDocPositionState() : InDocPositionState(NO_PAYLOAD), _owner(NULL) {}

BitmapInDocPositionState::~BitmapInDocPositionState() {}

InDocPositionIterator* BitmapInDocPositionState::CreateInDocIterator() const
{
    BitmapInDocPositionIterator* iter = new BitmapInDocPositionIterator();
    return iter;
}

void BitmapInDocPositionState::Clone(BitmapInDocPositionState* state) const
{
    state->_option = _option;
    state->_docId = _docId;
    state->_termFreq = _termFreq;
}

void BitmapInDocPositionState::Free()
{
    if (_owner) {
        _owner->Free(this);
    }
}
} // namespace indexlib::index
