#pragma once

#include "BinaryOpExpression.hpp"

struct AddExpression : BinaryOpExpression {
    AddExpression(Expression *, Expression *);

    ~AddExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;
};