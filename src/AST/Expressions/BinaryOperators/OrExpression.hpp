#pragma once

#include "BinaryOpExpression.hpp"

struct OrExpression : BinaryOpExpression {
    OrExpression(Expression *, Expression *);

    ~OrExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};