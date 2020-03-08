#pragma once

#include <vector>
#include <memory>

#include "FrontEnd/AST/Statements/StatementList.hpp"
#include "FrontEnd/AST/Statements/Statement.hpp"

struct Block : ASTNode {
    std::vector<std::shared_ptr<Statement>> stmts;

    explicit Block(StatementList *);

    ~Block() override = default;

    void print() const override;

    void fold_constants() override;
};