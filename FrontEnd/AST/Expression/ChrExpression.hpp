#pragma once

#include <memory>

#include "Expression.hpp"

struct ChrExpression : Expression {
    std::unique_ptr<Expression> expr;

    explicit ChrExpression(Expression *);

    ~ChrExpression() override = default;

    void accept(Visitor &) override;
};