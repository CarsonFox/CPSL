#pragma once

#include <vector>
#include <memory>

#include "src/AST/Statements/StatementList.hpp"
#include "src/AST/Statements/Statement.hpp"

struct Block : ASTNode {
    std::vector<std::shared_ptr<Statement>> stmts;

    explicit Block(StatementList *);

    ~Block() override = default;

    void print() const override;

    void fold_constants() override;

    void emit(SymbolTable &table, RegisterPool &pool) override;
};