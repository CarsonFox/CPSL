#pragma once

#include <variant>

#include "Expression.hpp"

struct LiteralExpression : Expression {
    std::variant<int, char> value;

    explicit LiteralExpression(int);

    explicit LiteralExpression(char);

    ~LiteralExpression() override = default;

    void print() const override;

    bool isConst() const override;
};
