#pragma once

#include "BinaryOpExpression.hpp"

struct LessExpression : BinaryOpExpression {
    LessExpression(Expression *, Expression *);

    ~LessExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};