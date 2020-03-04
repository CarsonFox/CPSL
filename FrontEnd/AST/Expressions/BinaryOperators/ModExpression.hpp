#pragma once

#include "BinaryOpExpression.hpp"

struct ModExpression : BinaryOpExpression {
    ModExpression(Expression *, Expression *);

    ~ModExpression() override = default;

    void print() const override;
};