#pragma once

#include "Type.hpp"

struct BuiltinType : Type {
    void print() const override;

    int getSize(SymbolTable &) override;
};