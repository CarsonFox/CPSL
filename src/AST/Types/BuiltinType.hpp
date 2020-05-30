#pragma once

#include "Type.hpp"

struct BuiltinType : Type {
    const Expression::type type;

    BuiltinType(Expression::type);

    void print() const override;

    int getSize(SymbolTable &) override;

    Expression::type getTypeEnum(SymbolTable &table) const override;
};