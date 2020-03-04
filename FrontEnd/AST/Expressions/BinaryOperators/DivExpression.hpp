#pragma once

#include "BinaryOpExpression.hpp"

struct DivExpression : BinaryOpExpression {
    DivExpression(Expression *, Expression *);

    ~DivExpression() override = default;

    void print() const override;
};