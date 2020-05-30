#pragma once

#include "ExpressionList.hpp"

struct FunctionCallExpression : Expression {
    std::string id;
    std::vector<std::shared_ptr<Expression>> args;

    FunctionCallExpression(char *, ExpressionList *);

    ~FunctionCallExpression() override = default;

    void print() const override;

    bool isConst() const override;

    std::optional<int> try_fold() override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;

    type getType(SymbolTable &table) override;
};