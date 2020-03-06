#pragma once

#include "UnaryOpExpression.hpp"

struct NotExpression : UnaryOpExpression {
    explicit NotExpression(Expression *);

    ~NotExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    bool isConst() const override;
};