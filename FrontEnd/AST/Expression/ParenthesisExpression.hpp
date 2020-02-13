#pragma once

#include <memory>

#include "Expression.hpp"

struct ParenthesisExpression : Expression {
    std::unique_ptr<Expression> expr;

    explicit ParenthesisExpression(Expression *);

    ~ParenthesisExpression() override = default;

    void accept(Visitor &) override;
};