#pragma once

#include <memory>

#include "Expression.hpp"

//TODO: Pred and succ have different behavior for booleans.
//This requires a boolean type

struct PredExpression : Expression {
    std::shared_ptr<Expression> expr;

    explicit PredExpression(Expression *);

    ~PredExpression() override = default;

    void print() const override;

    bool isConst() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;
};