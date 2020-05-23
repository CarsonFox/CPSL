#pragma once

#include "UnaryOpExpression.hpp"

struct NegExpression : UnaryOpExpression {
    explicit NegExpression(Expression *);

    ~NegExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    bool isConst() const override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};