#pragma once

#include "BinaryOpExpression.hpp"

struct GreaterEqualExpression : BinaryOpExpression {
    GreaterEqualExpression(Expression *, Expression *);

    ~GreaterEqualExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};