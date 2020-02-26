#pragma once

#include "BinaryOpExpression.hpp"

struct EqualExpression : BinaryOpExpression {
    EqualExpression(Expression *, Expression *);

    ~EqualExpression() override = default;

    void print() const override;
};