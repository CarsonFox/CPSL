#pragma once

#include <memory>

#include "FrontEnd/AST/Expressions/Expression.hpp"

struct BinaryOpExpression : Expression {
    std::shared_ptr<Expression> left, right;

    BinaryOpExpression(Expression *l, Expression *r);

    ~BinaryOpExpression() override = default;

    bool isConst() const override;
};