/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "src/rule_unconditional.h"


namespace modsecurity {


bool RuleUnconditional::evaluate(Transaction *trans,
    RuleMessage &ruleMessage) {
    RuleWithActions::evaluate(trans, ruleMessage);

    ms_dbg_a(trans, 4, "(Rule: " + std::to_string(getId()) \
        + ") Executing unconditional rule...");

    executeActionsIndependentOfChainedRuleResult(trans,
        ruleMessage);

    executeActionsAfterFullMatch(trans, ruleMessage);

    performLogging(trans, ruleMessage);

    return true;
}

}  // namespace modsecurity
