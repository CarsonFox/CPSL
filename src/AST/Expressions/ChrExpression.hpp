#pragma once

#include <memory>

#include "Expression.hpp"

struct ChrExpression : Expression {
    std::shared_ptr<Expression> expr;

    explicit ChrExpression(Expression *);

    ~ChrExpression() override = default;

    void print() const override;

    bool isConst() const override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};