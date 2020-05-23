#pragma once

#include "BinaryOpExpression.hpp"

struct MulExpression : BinaryOpExpression {
    MulExpression(Expression *, Expression *);

    ~MulExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};