#pragma once

#include <memory>

#include "Type.hpp"

struct Expression;

struct ArrayType : Type {
    int left, right;
    std::shared_ptr<Type> type;

    ArrayType(Expression *, Expression *, Type *);

    ~ArrayType() override = default;

    void print() const override;

    void fold_constants() override;

    int getSize(SymbolTable &table) override;

    Expression::type getTypeEnum(SymbolTable &table) const override;
};