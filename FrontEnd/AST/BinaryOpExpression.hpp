#pragma once

#include <memory>
#include <functional>
#include <utility>

#include "Expression.hpp"

struct BinaryOpExpression : Expression {
    std::unique_ptr<Expression> left, right;
    std::function<int(int, int)> op;
    const char opChar;

    ~BinaryOpExpression() override = default;

    static BinaryOpExpression *Sub(Expression *, Expression *);

    void accept(Visitor &visitor) override {
        visitor.visit(this);
    }

private:
    BinaryOpExpression(Expression *l, Expression *r, std::function<int(int, int)> f, char c);
};