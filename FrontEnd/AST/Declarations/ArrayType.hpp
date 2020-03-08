#pragma once

#include <memory>

#include "Type.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"

struct ArrayType : Type {
    std::shared_ptr<Expression> left, right;
    std::shared_ptr<Type> type;

    ArrayType(Expression *, Expression *, Type *);

    ~ArrayType() override = default;

    void print() const override;

    void fold_constants() override;
};