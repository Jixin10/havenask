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
#ifndef FSLIB_DUMMYFILE_H
#define FSLIB_DUMMYFILE_H

#include "autil/Log.h"
#include "fslib/common/common_define.h"
#include "fslib/common/common_type.h"
#include "fslib/fs/File.h"

FSLIB_BEGIN_NAMESPACE(fs);

class DummyFile : public File
{
public:
    DummyFile(ErrorCode ec = EC_PARSEFAIL);
    ~DummyFile();

public:
    /*override*/ ssize_t read(void* buffer, size_t length);

    /*override*/ ssize_t write(const void* buffer, size_t length);

    /*override*/ ssize_t pread(void* buffer, size_t length, off_t offset);

    /*override*/ ssize_t pwrite(const void* buffer, size_t length, off_t offset);

    /*override*/ ErrorCode flush();

    /*override*/ ErrorCode close();

    /*override*/ ErrorCode seek(int64_t offset, SeekFlag flag);

    /*override*/ int64_t tell();

    /*override*/ bool isOpened() const;

    /*override*/ bool isEof();

private:
    static std::string _dummyFileName;
};

FSLIB_TYPEDEF_AUTO_PTR(DummyFile);

FSLIB_END_NAMESPACE(fs);

#endif //FSLIB_DUMMYFILE_H
