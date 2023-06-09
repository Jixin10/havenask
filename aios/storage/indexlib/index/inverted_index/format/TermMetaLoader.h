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

#include <memory>

#include "indexlib/file_system/ByteSliceReader.h"
#include "indexlib/file_system/file/FileReader.h"
#include "indexlib/index/inverted_index/format/PostingFormatOption.h"
#include "indexlib/index/inverted_index/format/TermMeta.h"

namespace indexlib::index {

class TermMetaLoader
{
public:
    TermMetaLoader(const PostingFormatOption& option);
    TermMetaLoader() = default;
    ~TermMetaLoader() = default;

    void Load(file_system::ByteSliceReader* sliceReader, TermMeta& termMeta) const;
    void Load(const std::shared_ptr<file_system::FileReader>& reader, TermMeta& termMeta) const;
    void Load(uint8_t*& dataCursor, size_t& leftSize, TermMeta& termMeta) const;

private:
    PostingFormatOption _option;
};

} // namespace indexlib::index
