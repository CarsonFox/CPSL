#pragma once

#include <memory>
#include <array>
#include <string>

#include "Expression.hpp"

enum BinaryOp {
    Or, And, Equal, NotEqual, Less, LessEqual,
    Greater, GreaterEqual, Add, Sub, Mul, Div, Mod,
};

struct BinaryOpExpression : Expression {
    std::shared_ptr<Expression> left, right;
    BinaryOp type;

    BinaryOpExpression(Expression *l, Expression *r, BinaryOp t);

    ~BinaryOpExpression() override = default;

    void print() const override;

    bool isConst() const override;
};