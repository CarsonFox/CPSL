#pragma once

#include "Expression.hpp"

struct LiteralExpression : Expression {
    int value;

    explicit LiteralExpression(int);

    ~LiteralExpression() override = default;

    void accept(Visitor &) override;
};
