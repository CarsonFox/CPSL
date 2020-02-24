#pragma once

#include <memory>

#include "Expression.hpp"

/*
 * Keeping this just so pretty-printing doesn't
 * change the syntax of the program. Parentheses will
 * be removed during constant folding.
 */

struct ParenthesisExpression : Expression {
    std::unique_ptr<Expression> expr;

    explicit ParenthesisExpression(Expression *);

    ~ParenthesisExpression() override = default;

    void print() const override;

    bool isConst() const override;
};