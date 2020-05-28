#pragma once

#include "Statement.hpp"

struct StopStatement : Statement {
    StopStatement() = default;

    ~StopStatement() override = default;

    void print() const override;

    void emit(SymbolTable &table, RegisterPool &pool) override;
};