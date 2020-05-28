#pragma once

#include "BinaryOpExpression.hpp"

struct GreaterExpression : BinaryOpExpression {
    GreaterExpression(Expression *, Expression *);

    GreaterExpression(Expression *, std::shared_ptr<Expression>);

    ~GreaterExpression() override = default;

    void print() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};