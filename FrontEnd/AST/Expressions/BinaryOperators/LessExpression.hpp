#pragma once

#include "BinaryOpExpression.hpp"

struct LessExpression : BinaryOpExpression {
    LessExpression(Expression *, Expression *);

    ~LessExpression() override = default;

    void print() const override;
};