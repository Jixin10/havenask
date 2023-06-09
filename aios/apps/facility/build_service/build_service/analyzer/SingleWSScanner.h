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
#ifndef ISEARCH_BS_SINGLEWSSCANNER_H
#define ISEARCH_BS_SINGLEWSSCANNER_H
#include "build_service/util/Log.h"
#ifndef __FLEX_LEXER_H
#include <FlexLexer.h>
#endif

namespace build_service { namespace analyzer {
class SingleWSScanner : public yyFlexLexer
{
public:
    SingleWSScanner(std::istream* input, std::ostream* output)
        : yyFlexLexer(input, output)
        , _currPos(0)
        , _isStopWord(false)
    {
    }

    virtual ~SingleWSScanner() {}

public:
    virtual bool lex(const char*& pText, int& length);

    bool hasInvalidChar() const { return !_invalidCharPosVec.empty(); }
    const std::vector<int32_t>& getInvalidCharPosVec() const { return _invalidCharPosVec; }

    int32_t getCurrPos() const { return _currPos; }

    bool isStopWord() const { return _isStopWord; }

private:
    std::vector<int32_t> _invalidCharPosVec;
    int32_t _currPos;
    bool _isStopWord;

private:
    BS_LOG_DECLARE();
};

}} // namespace build_service::analyzer
#endif
