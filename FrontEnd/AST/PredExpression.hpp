#pragma once

#include <memory>

#include "Expression.hpp"

struct PredExpression : Expression {
    std::unique_ptr<Expression> expr;

    explicit PredExpression(Expression *);

    ~PredExpression() override = default;

    void accept(Visitor &) override;
};