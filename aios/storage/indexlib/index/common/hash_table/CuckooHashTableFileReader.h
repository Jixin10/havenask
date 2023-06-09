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

#include "autil/mem_pool/Pool.h"
#include "indexlib/file_system/IDirectory.h"
#include "indexlib/file_system/ReaderOption.h"
#include "indexlib/file_system/WriterOption.h"
#include "indexlib/file_system/file/FileReader.h"
#include "indexlib/file_system/file/FileWriter.h"
#include "indexlib/index/common/hash_table/CuckooHashTable.h"
#include "indexlib/index/common/hash_table/HashTableFileReaderBase.h"
#include "indexlib/util/PathUtil.h"

namespace indexlibv2::index {

// FORMAT: see cuckoo_hash_table.h
template <typename _KT, typename _VT, bool HasSpecialKey = ClosedHashTableTraits<_KT, _VT, false>::HasSpecialKey,
          bool useCompactBucket = false>
class CuckooHashTableFileReaderBase : public HashTableFileReaderBase
{
public:
    CuckooHashTableFileReaderBase() = default;
    ~CuckooHashTableFileReaderBase() = default;

public:
    typedef CuckooHashTable<_KT, _VT, HasSpecialKey, useCompactBucket> HashTable;
    typedef typename HashTable::HashTableHeader HashTableHeader;
    typedef typename ClosedHashTableTraits<_KT, _VT, useCompactBucket>::Bucket Bucket;

private:
    bool ReadHeader(const std::shared_ptr<indexlib::file_system::IDirectory>& directory,
                    const indexlib::file_system::FileReaderPtr& fileReader)
    {
        size_t size = fileReader->GetLogicLength();
        HashTableHeader header;
        if (size < sizeof(header)) {
            AUTIL_LOG(ERROR, "read header failed, header size[%lu], fileLength[%lu]", sizeof(header),
                      fileReader->GetLogicLength());
            return false;
        }
        std::string fileName;
        indexlib::util::PathUtil::GetRelativePath(directory->GetLogicalPath(), fileReader->GetLogicalPath(), fileName);
        std::string sliceFileName = fileName + ".header";
        _headerReader = directory->CreateFileReader(sliceFileName, indexlib::file_system::FSOT_SLICE).GetOrThrow();
        if (!_headerReader) {
            size_t sliceLen = sizeof(header);
            auto fileWriter =
                directory->CreateFileWriter(sliceFileName, indexlib::file_system::WriterOption::Slice(sliceLen, 1))
                    .GetOrThrow();
            fileWriter->Truncate(sliceLen).GetOrThrow();
            _headerReader = directory->CreateFileReader(sliceFileName, indexlib::file_system::FSOT_SLICE).GetOrThrow();
            fileWriter->Close().GetOrThrow();
            if (sliceLen != fileReader->Read(_headerReader->GetBaseAddress(), sliceLen, 0).GetOrThrow()) {
                AUTIL_LOG(ERROR, "read header failed, header size[%lu], fileLength[%lu]", sizeof(header),
                          fileReader->GetLogicLength());
                return false;
            }
        }
        header = *(HashTableHeader*)_headerReader->GetBaseAddress();
        _bucketCount = header.bucketCount;
        _keyCount = header.keyCount;
        _nu_hashFunc = header.nu_hashFunc;
        if (size < sizeof(HashTableHeader) + _bucketCount * sizeof(Bucket)) {
            AUTIL_LOG(ERROR, "too small size[%lu], header size[%lu], bucket size[%lu]", size, sizeof(HashTableHeader),
                      _bucketCount * sizeof(Bucket));
            return false;
        }
        _blockCount = (size - sizeof(HashTableHeader) - (HasSpecialKey ? sizeof(Bucket) * 2 : 0)) / sizeof(Bucket) /
                      HashTable::BLOCK_SIZE;
        if (_blockCount < 1) {
            AUTIL_LOG(ERROR, "size[%lu] too small", size);
            return false;
        }
        _fileReader = fileReader.get();
        return true;
    }

public:
    bool Init(const std::shared_ptr<indexlib::file_system::IDirectory>& directory,
              const indexlib::file_system::FileReaderPtr& fileReader) override
    {
        if (!ReadHeader(directory, fileReader)) {
            return false;
        }
        _fileReader = fileReader.get();
        return true;
    }

    using HashTableFileReaderBase::Find;
    FL_LAZY(indexlib::util::Status)
    Find(const _KT& key, _VT& value, indexlib::util::BlockAccessCounter* blockCounter,
         autil::TimeoutTerminator* timeoutTerminator) const
    {
        indexlib::file_system::ReadOption option;
        option.blockCounter = blockCounter;
        option.timeoutTerminator = timeoutTerminator;
        option.advice = indexlib::file_system::IO_ADVICE_LOW_LATENCY;
        for (uint32_t hashCnt = 0; hashCnt < _nu_hashFunc; ++hashCnt) {
            const _KT& hash = HashTable::CuckooHash(key, hashCnt);
            uint64_t bucketId = HashTable::GetFirstBucketIdInBlock(hash, _blockCount);
            Bucket block[HashTable::BLOCK_SIZE];
            auto result = (FL_COAWAIT _fileReader->ReadAsyncCoro(
                               block, sizeof(block), sizeof(HashTableHeader) + bucketId * sizeof(Bucket), option))
                              .GetOrThrow();
            (void)result;

            for (uint32_t inBlockId = 0; inBlockId < HashTable::BLOCK_SIZE; ++inBlockId) {
                Bucket& curBucket = block[inBlockId];
                if (curBucket.IsEmpty()) {
                    continue;
                }
                if (curBucket.IsEqual(key)) {
                    value = curBucket.Value();
                    FL_CORETURN curBucket.IsDeleted() ? indexlib::util::DELETED : indexlib::util::OK;
                }
            }
        }
        FL_CORETURN indexlib::util::NOT_FOUND;
    }
    uint64_t Size() const { return _keyCount; }
    bool IsFull() const { return true; }

protected:
    indexlib::file_system::FileReaderPtr _headerReader;
    uint64_t _bucketCount = 0;
    uint64_t _blockCount;
    uint64_t _keyCount = 0;
    uint8_t _nu_hashFunc = 2;
    indexlib::file_system::FileReader* _fileReader = nullptr;

private:
    AUTIL_LOG_DECLARE();
};

////////////////////////////////////////////////////////////////////////
template <typename _KT, typename _VT, bool HasSpecialKey, bool useCompactBucket>
alog::Logger* CuckooHashTableFileReaderBase<_KT, _VT, HasSpecialKey, useCompactBucket>::_logger =
    alog::Logger::getLogger("indexlib.index.CuckooHashTableFileReaderBase");

////////////////////////////////////////////////////////////////////////
// hide some methods
template <typename _KT, typename _VT, bool HasSpecialKey = ClosedHashTableTraits<_KT, _VT, false>::HasSpecialKey,
          bool useCompactBucket = false>
class CuckooHashTableFileReader : public CuckooHashTableFileReaderBase<_KT, _VT, HasSpecialKey, useCompactBucket>
{
public:
    typedef CuckooHashTableFileReaderBase<_KT, _VT, HasSpecialKey, useCompactBucket> Base;

public:
    bool Init(const std::shared_ptr<indexlib::file_system::IDirectory>& directory,
              const indexlib::file_system::FileReaderPtr& fileReader) override
    {
        return Base::Init(directory, fileReader);
    }
    using Base::Find;
    FL_LAZY(indexlib::util::Status)
    Find(uint64_t key, autil::StringView& value, indexlib::util::BlockAccessCounter* blockCounter,
         autil::mem_pool::Pool* pool, autil::TimeoutTerminator* timeoutTerminator) const override final
    {
        assert(pool);
        _VT* typedValue = (_VT*)pool->allocate(sizeof(_VT));
        auto status = FL_COAWAIT Find((_KT)key, *typedValue, blockCounter, timeoutTerminator);
        value = {(char*)typedValue, sizeof(_VT)};
        FL_CORETURN status;
    }
};

template <typename _KT, typename _VT, bool useCompactBucket>
class CuckooHashTableFileReader<_KT, _VT, true, useCompactBucket>
    : public CuckooHashTableFileReaderBase<_KT, _VT, false, useCompactBucket>
{
public:
    typedef typename CuckooHashTableBase<_KT, _VT, true, useCompactBucket>::HashTableHeader HashTableHeader;
    typedef typename ClosedHashTableTraits<_KT, _VT, useCompactBucket>::Bucket Bucket;
    typedef typename ClosedHashTableTraits<_KT, _VT, useCompactBucket>::SpecialBucket SpecialBucket;

private:
    typedef CuckooHashTableFileReaderBase<_KT, _VT, false, useCompactBucket> Base;
    using Base::_bucketCount;
    using Base::_fileReader;

public:
    using Base::Find;
    bool Init(const std::shared_ptr<indexlib::file_system::IDirectory>& directory,
              const indexlib::file_system::FileReaderPtr& fileReader) override
    {
        return Base::Init(directory, fileReader);
    }
    FL_LAZY(indexlib::util::Status)
    Find(uint64_t key, autil::StringView& value, indexlib::util::BlockAccessCounter* blockCounter,
         autil::mem_pool::Pool* pool, autil::TimeoutTerminator* timeoutTerminator) const override final
    {
        assert(pool);
        _VT* typedValue = (_VT*)pool->allocate(sizeof(_VT));
        auto status = FL_COAWAIT Find((_KT)key, *typedValue, blockCounter, timeoutTerminator);
        value = {(char*)typedValue, sizeof(_VT)};
        FL_CORETURN status;
    }

    FL_LAZY(indexlib::util::Status)
    Find(const _KT& key, _VT& value, indexlib::util::BlockAccessCounter* blockCounter,
         autil::TimeoutTerminator* timeoutTerminator) const
    {
        if (likely(!Bucket::IsEmptyKey(key) && !Bucket::IsDeleteKey(key))) {
            FL_CORETURN FL_COAWAIT Base::Find(key, value, blockCounter, timeoutTerminator);
        }

        size_t offset = sizeof(HashTableHeader) + _bucketCount * sizeof(Bucket) +
                        (Bucket::IsEmptyKey(key) ? 0 : sizeof(SpecialBucket));
        SpecialBucket bucket;
        indexlib::file_system::ReadOption option;
        option.blockCounter = blockCounter;
        option.timeoutTerminator = timeoutTerminator;
        option.advice = indexlib::file_system::IO_ADVICE_LOW_LATENCY;
        auto result = FL_COAWAIT _fileReader->ReadAsyncCoro(&bucket, sizeof(bucket), offset, option);
        if (!result.OK()) {
            FL_CORETURN indexlib::util::FAIL;
        }
        if (bucket.IsEmpty()) {
            FL_CORETURN indexlib::util::NOT_FOUND;
        }
        value = bucket.Value();
        FL_CORETURN bucket.IsDeleted() ? indexlib::util::DELETED : indexlib::util::OK;
    }
};
} // namespace indexlibv2::index
