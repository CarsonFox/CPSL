#pragma once

#include <memory>
#include <vector>
#include <tuple>

#include "Statement.hpp"
#include "StatementList.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"

struct IfStatement : Statement {
    std::unique_ptr<Expression> pred;
    std::vector<std::unique_ptr<Statement>> stmts;
    //What a type declaration
    std::vector<std::pair<std::unique_ptr<Expression>, std::vector<std::unique_ptr<Statement>>>> elseIfs;
    std::vector<std::unique_ptr<Statement>> elseStmts;

    IfStatement(Expression *, StatementList *);

    ~IfStatement() override = default;

    void addElseIf(Expression *, StatementList *);

    void addElse(StatementList *);

    void accept(Visitor &) override;
};