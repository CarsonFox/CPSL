#pragma once

#include "BinaryOpExpression.hpp"

struct GreaterExpression : BinaryOpExpression {
    GreaterExpression(Expression *, Expression *);

    ~GreaterExpression() override = default;

    void print() const override;
};