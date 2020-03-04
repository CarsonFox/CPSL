#pragma once

#include "BinaryOpExpression.hpp"

struct LessEqualExpression : BinaryOpExpression {
    LessEqualExpression(Expression *, Expression *);

    ~LessEqualExpression() override = default;

    void print() const override;
};