#pragma once

#include "Statement.hpp"

struct EmptyStatement : Statement {
    EmptyStatement() = default;

    ~EmptyStatement() override = default;

    void print() const override {}

    void emit(SymbolTable &, RegisterPool &) override {}
};