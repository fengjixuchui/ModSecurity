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

#ifdef __cplusplus
#include <stack>
#include <vector>
#include <string>
#include <list>
#include <memory>
#include <utility>
#endif

#ifndef HEADERS_MODSECURITY_RULE_WITH_OPERATOR_H_
#define HEADERS_MODSECURITY_RULE_WITH_OPERATOR_H_

#include "modsecurity/transaction.h"
#include "modsecurity/modsecurity.h"
#include "modsecurity/variable_value.h"
#include "modsecurity/rule.h"
#include "modsecurity/rule_with_actions.h"

#ifdef __cplusplus

namespace modsecurity {


class RuleWithOperator : public RuleWithActions {
 public:
    RuleWithOperator(operators::Operator *_op,
            Variables::Variables *_variables,
            std::vector<actions::Action *> *_actions,
            Transformations *transformations,
            std::unique_ptr<std::string> fileName,
            int lineNumber);
    virtual ~RuleWithOperator();

    bool evaluate(Transaction *transaction) override;

    void getVariablesExceptions(Transaction *t,
        Variables::Variables *exclusion, Variables::Variables *addition);
    inline void getFinalVars(Variables::Variables *vars,
        Variables::Variables *eclusion, Transaction *trans);

    bool executeOperatorAt(Transaction *trasn, std::string key,
        std::string value);

    inline void updateMatchedVars(Transaction *trasn, const std::string &key,
        const std::string &value);
    inline void cleanMatchedVars(Transaction *trasn);


    std::string getOperatorName();


    virtual std::string getReference() override {
        return std::to_string(getId());
    }

 private:
    modsecurity::Variables::Variables *m_variables;
    operators::Operator *m_operator;
};


}  // namespace modsecurity
#endif


#endif  // HEADERS_MODSECURITY_RULE_WITH_OPERATOR_H_