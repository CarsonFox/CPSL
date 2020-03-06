#pragma once

#include "Expression.hpp"

struct LiteralExpression : Expression {
    bool isChar;
    int value;

    explicit LiteralExpression(int);

    explicit LiteralExpression(char);

    ~LiteralExpression() override = default;

    void print() const override;

    bool isConst() const override;

    std::optional<int> try_fold() override;
};
