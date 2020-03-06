#pragma once

#include "UnaryOpExpression.hpp"

struct NegExpression : UnaryOpExpression {
    explicit NegExpression(Expression *);

    ~NegExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() const override;

    bool isConst() const override;
};