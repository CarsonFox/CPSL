#pragma once

#include "BinaryOpExpression.hpp"

struct SubExpression : BinaryOpExpression {
    SubExpression(Expression *, Expression *);

    ~SubExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};