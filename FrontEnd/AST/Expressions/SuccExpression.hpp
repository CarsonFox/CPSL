#pragma once

#include <memory>

#include "Expression.hpp"

struct SuccExpression : Expression {
    std::unique_ptr<Expression> expr;

    explicit SuccExpression(Expression *);

    ~SuccExpression() override = default;

    void print() const override;

    bool isConst() const override;
};