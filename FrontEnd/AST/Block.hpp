#pragma once

#include <vector>
#include <memory>

#include "Statements/StatementList.hpp"
#include "Statements/Statement.hpp"

struct Block : ASTNode {
    std::vector<std::unique_ptr<Statement>> stmts;

    explicit Block(StatementList *);

    ~Block() override = default;

    void accept(Visitor &) override;
};