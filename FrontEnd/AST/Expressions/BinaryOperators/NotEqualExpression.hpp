#pragma once

#include "BinaryOpExpression.hpp"

struct NotEqualExpression : BinaryOpExpression {
    NotEqualExpression(Expression *, Expression *);

    ~NotEqualExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;
};