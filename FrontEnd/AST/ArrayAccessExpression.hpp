#pragma once

#include <memory>

#include "LValue.hpp"

struct ArrayAccessExpression : LValue {
    std::unique_ptr<LValue> left;
    std::unique_ptr<Expression> right;

    ArrayAccessExpression(LValue *, Expression *);

    ~ArrayAccessExpression() override = default;

    void accept(Visitor &);
};