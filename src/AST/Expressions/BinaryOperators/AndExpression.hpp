#pragma once

#include "BinaryOpExpression.hpp"

struct AndExpression : BinaryOpExpression {
    AndExpression(Expression *, Expression *);

    ~AndExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;
};