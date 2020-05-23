#pragma once

#include "BinaryOpExpression.hpp"

struct EqualExpression : BinaryOpExpression {
    EqualExpression(Expression *, Expression *);

    ~EqualExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};