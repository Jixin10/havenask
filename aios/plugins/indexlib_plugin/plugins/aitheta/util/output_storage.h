/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     indexlib_fs_index_storage.h
 *   \author   richard.sy
 *   \date     May 2018
 *   \version  1.0.0
 *   \brief
 */

#ifndef __AITHETA_OUTPUT_STORAGE_H
#define __AITHETA_OUTPUT_STORAGE_H

#include <aitheta/index_params.h>
#include <aitheta/index_storage.h>
#include "indexlib/common_define.h"
#include "indexlib/misc/log.h"
#include "indexlib/file_system/file/BufferedFileWriter.h"
#include "indexlib/file_system/Directory.h"
#include "indexlib/file_system/fslib/FslibWrapper.h"

namespace indexlib {
namespace aitheta_plugin {

class OutputStorage : public aitheta::IndexStorage {
 public:
    class Handler : public aitheta::IndexStorage::Handler {
     public:
        Handler(indexlib::file_system::FileWriterPtr &writer, size_t size) : mWriter(writer), mSize(size) {}
        ~Handler(void) {}

     public:
        // Close the handler and cleanup resource
        void close(void) {}
        // Reset the handler (include resource)
        void reset(void) {}
        // Write data into the storage
        size_t write(const void *data, size_t len);
        // Write data into the storage with offset
        size_t write(size_t offset, const void *data, size_t len);
        // Read data from the storage (Zero-copy)
        size_t read(const void **data, size_t len) { return 0; }
        // Read data from the storage with offset (Zero-copy)
        size_t read(size_t offset, const void **data, size_t len) { return 0; }
        // Read data from the storage
        size_t read(void *data, size_t len) { return 0; }
        // Read data from the storage with offset
        size_t read(size_t offset, void *data, size_t len) { return 0; }
        // Retrieve size of file
        size_t size(void) const { return mSize; }

     private:
        indexlib::file_system::FileWriterPtr mWriter;
        size_t mSize;

     private:
        IE_LOG_DECLARE();
    };

 public:
    OutputStorage(indexlib::file_system::FileWriterPtr writer) : mWriter(writer) {}
    ~OutputStorage(void) {}

 public:
    // Initialize Storage
    int init(const aitheta::StorageParams &params) override { return 0; };
    // Cleanup Storage
    int cleanup(void) override { return 0; }
    // Create a file with size
    aitheta::IndexStorage::Handler::Pointer create(const std::string &path, size_t size) override;
    // Open a file
    aitheta::IndexStorage::Handler::Pointer open(const std::string &path, bool rdonly = false) override;
    // Retrieve non-zero if the storage support random reads
    bool hasRandRead(void) const override { return false; }
    // Retrieve non-zero if the storage support random writes
    bool hasRandWrite(void) const override { return false; }
    // 探测路径是否存在
    bool access(const std::string &path) const override { return true; }

 private:
    indexlib::file_system::FileWriterPtr mWriter;

 private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(OutputStorage);

}
}

#endif  //__AITHETA_OUTPUT_STORAGE_H__
