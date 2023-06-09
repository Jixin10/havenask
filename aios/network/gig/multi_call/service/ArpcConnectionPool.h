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
#ifndef ISEARCH_MULTI_CALL_ARPCCONNECTIONPOOL_H
#define ISEARCH_MULTI_CALL_ARPCCONNECTIONPOOL_H

#include "aios/network/arpc/arpc/ANetRPCChannelManager.h"
#include "aios/network/gig/multi_call/common/common.h"
#include "aios/network/gig/multi_call/service/ConnectionPool.h"

namespace multi_call {

class ArpcConnectionPool : public ConnectionPool {
public:
    ArpcConnectionPool(bool isRawArpc = false);
    ~ArpcConnectionPool();

private:
    ArpcConnectionPool(const ArpcConnectionPool &);
    ArpcConnectionPool &operator=(const ArpcConnectionPool &);

public:
    bool init(const ProtocolConfig &config) override;

private:
    bool _isRawArpc;
    std::shared_ptr<arpc::ANetRPCChannelManager> _rpcChannelManager;

private:
    AUTIL_LOG_DECLARE();
};

MULTI_CALL_TYPEDEF_PTR(ArpcConnectionPool);

} // namespace multi_call

#endif // ISEARCH_MULTI_CALL_ARPCCONNECTIONPOOL_H
