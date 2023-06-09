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

#include "aios/network/gig/multi_call/proto/NewHeartbeat.pb.h"
#include "aios/network/gig/multi_call/common/common.h"
#include "autil/Lock.h"
#include <unordered_map>

namespace multi_call {

class TopoInfoBuilder;

struct SignatureMap {
    uint64_t clientId;
    int64_t serverSignature;
    std::map<SignatureTy, BizTopoSignature> topoSignatureMap;
};

MULTI_CALL_TYPEDEF_PTR(SignatureMap);

class BizStat;

class BizTopo
{
public:
    BizTopo(SignatureTy publishId, PublishGroupTy group);
    ~BizTopo();
public:
    bool init(const ServerBizTopoInfo &info, const std::shared_ptr<BizStat> &bizStat);
    void updateVolatileInfo(const BizVolatileInfo &info);
    void stop();
    void fillBizTopoDiff(const BizTopoSignature &clientSideSignature, BizTopoDef *topoDef) const;
    void fillBizTopo(BizTopoDef *topoDef) const;
    void fillPropagationStat(BizTopoDef *topoDef) const;
    void addToBuilder(TopoInfoBuilder &builder) const;
    SignatureTy getTopoSignature() const {
        return _signature.topo;
    }
    SignatureTy getPublishId() const {
        return _signature.publishId;
    }
    PublishGroupTy getGroup() const {
        return _group;
    }
    const std::string &getId() const {
        return _id;
    }
    const ServerBizTopoInfo &getTopoInfo() const {
        return _info;
    }
    void toString(std::string &ret) const;
private:
    void initTopoSignature();
    void initMetaSignature();
    void initTagSignature();
    void fillSignature(TopoSignatureDef *signatureDef) const;
    void fillTopoKey(BizTopoKeyDef *keyDef) const;
    void fillMeta(BizMetasDef *metaDef) const;
    void fillTag(BizTagsDef *tagsDef) const;
private:
    PublishGroupTy _group;
    std::string _id;
    std::shared_ptr<BizStat> _bizStat;
    mutable autil::ReadWriteLock _tagLock;
    ServerBizTopoInfo _info;
    BizTopoSignature _signature;
private:
    AUTIL_LOG_DECLARE();
};

MULTI_CALL_TYPEDEF_PTR(BizTopo);

typedef std::map<SignatureTy, BizTopoPtr> BizTopoMap;
MULTI_CALL_TYPEDEF_PTR(BizTopoMap);

}
