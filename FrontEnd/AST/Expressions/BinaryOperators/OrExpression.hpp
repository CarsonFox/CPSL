#pragma once

#include "BinaryOpExpression.hpp"

struct OrExpression : BinaryOpExpression {
    OrExpression(Expression *, Expression *);

    ~OrExpression() override = default;

    void print() const override;
};