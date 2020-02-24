#pragma once

#include <memory>
#include <functional>

#include "Expression.hpp"

enum UnaryOp {
    Neg,
    Not
};

struct UnaryOpExpression : Expression {
    std::unique_ptr<Expression> expr;
    UnaryOp type;

    UnaryOpExpression(Expression *, UnaryOp);

    ~UnaryOpExpression() override = default;

    void print() const override;

    bool isConst() const override;
};