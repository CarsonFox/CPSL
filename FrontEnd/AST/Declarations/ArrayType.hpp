#pragma once

#include <memory>

#include "Type.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"

struct ArrayType : Type {
    std::unique_ptr<Expression> left, right;
    std::unique_ptr<Type> type;

    ArrayType(Expression *, Expression *, Type *);

    ~ArrayType() override = default;

    void accept(Visitor &) override;
};