#pragma once

#include <vector>
#include <memory>

#include "Statement.hpp"
#include "src/AST/Expressions/ExpressionList.hpp"

struct WriteStatement : Statement {
    std::vector<std::shared_ptr<Expression>> args;

    explicit WriteStatement(ExpressionList *);

    ~WriteStatement() override = default;

    void print() const override;

    void fold_constants() override;

    void emit(SymbolTable &table, RegisterPool &pool) override;

private:
    void printIntegral(SymbolTable &table, RegisterPool &pool, const std::shared_ptr<Expression> &expr);

    void printCharacter(SymbolTable &table, RegisterPool &pool, const std::shared_ptr<Expression> &expr);

    void printString(SymbolTable &table, RegisterPool &pool, const std::shared_ptr<Expression> &expr);
};