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
#include "ha3/turing/variant/InnerResultVariant.h"

#include <iosfwd>
#include <memory>

#include "autil/Log.h"
#include "tensorflow/core/framework/variant_op_registry.h"
#include "tensorflow/core/platform/byte_order.h"

using namespace std;
using namespace tensorflow;

namespace isearch {
namespace turing {
AUTIL_LOG_SETUP(ha3, InnerResultVariant);

REGISTER_UNARY_VARIANT_DECODE_FUNCTION(InnerResultVariant, "InnerResult");

} // namespace turing
} // namespace isearch
