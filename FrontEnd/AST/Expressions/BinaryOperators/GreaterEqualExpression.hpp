#pragma once

#include "BinaryOpExpression.hpp"

struct GreaterEqualExpression : BinaryOpExpression {
    GreaterEqualExpression(Expression *, Expression *);

    ~GreaterEqualExpression() override = default;

    void print() const override;
};