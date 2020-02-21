#pragma once

#include <vector>
#include <memory>

#include "FrontEnd/AST/Statements/StatementList.hpp"
#include "FrontEnd/AST/Statements/Statement.hpp"

struct Block : ASTNode {
    std::vector<std::unique_ptr<Statement>> stmts;

    explicit Block(StatementList *);

    ~Block() override = default;

    void accept(Visitor &) override;
};