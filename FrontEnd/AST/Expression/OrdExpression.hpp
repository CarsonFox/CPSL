#pragma once

#include <memory>

#include "Expression.hpp"

struct OrdExpression : Expression {
    std::unique_ptr<Expression> expr;

    explicit OrdExpression(Expression *);

    ~OrdExpression() override = default;

    void accept(Visitor &) override;
};
