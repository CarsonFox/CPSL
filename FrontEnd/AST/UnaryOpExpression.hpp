#pragma once

#include <memory>
#include <functional>

#include "Expression.hpp"

enum UnaryOp {
    Neg
};

struct UnaryOpExpression : Expression {
    std::unique_ptr<Expression> expr;
    UnaryOp type;

    UnaryOpExpression(Expression *, UnaryOp);

    ~UnaryOpExpression() override = default;

    void accept(Visitor &) override;
};