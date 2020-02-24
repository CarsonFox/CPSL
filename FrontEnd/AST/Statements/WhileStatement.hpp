#pragma once

#include <memory>
#include <vector>

#include "Statement.hpp"
#include "StatementList.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"

struct WhileStatement : Statement {
    std::unique_ptr<Expression> pred;
    std::vector<std::unique_ptr<Statement>> stmts;

    WhileStatement(Expression *, StatementList *);

    ~WhileStatement() override = default;

    void print() const override;
};