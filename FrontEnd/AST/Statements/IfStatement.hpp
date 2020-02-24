#pragma once

#include <memory>
#include <vector>
#include <tuple>

#include "Statement.hpp"
#include "StatementList.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"

struct IfStatement : Statement {
    std::shared_ptr<Expression> pred;
    std::vector<std::shared_ptr<Statement>> stmts;
    //What a type declaration
    std::vector<std::pair<std::shared_ptr<Expression>, std::vector<std::shared_ptr<Statement>>>> elseIfs;
    std::vector<std::shared_ptr<Statement>> elseStmts;

    IfStatement(Expression *, StatementList *);

    ~IfStatement() override = default;

    void addElseIf(Expression *, StatementList *);

    void addElse(StatementList *);

    void print() const override;
};