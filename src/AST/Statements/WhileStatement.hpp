#pragma once

#include <memory>
#include <vector>

#include "Statement.hpp"
#include "StatementList.hpp"
#include "src/AST/Expressions/Expression.hpp"

struct WhileStatement : Statement {
    std::shared_ptr<Expression> pred;
    std::vector<std::shared_ptr<Statement>> stmts;

    WhileStatement(Expression *, StatementList *);

    ~WhileStatement() override = default;

    void print() const override;

    void fold_constants() override;
};