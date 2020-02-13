#pragma once

#include <memory>
#include <functional>
#include <utility>

#include "Expression.hpp"

enum BinaryOp {
    Or, And, Equal, NotEqual, Less, LessEqual,
    Greater, GreaterEqual, Add, Sub, Mul, Div, Mod,
};

struct BinaryOpExpression : Expression {
    std::unique_ptr<Expression> left, right;
    BinaryOp type;

    BinaryOpExpression(Expression *l, Expression *r, BinaryOp t);

    ~BinaryOpExpression() override = default;

    void accept(Visitor &visitor) override {
        visitor.visit(this);
    }
};