#pragma once

#include "BinaryOpExpression.hpp"

struct ModExpression : BinaryOpExpression {
    ModExpression(Expression *, Expression *);

    ~ModExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};