#pragma once

#include <memory>
#include <vector>

#include <FrontEnd/AST/Expressions/Expression.hpp>
#include "Statement.hpp"
#include "StatementList.hpp"

struct RepeatStatement : Statement {
    std::vector<std::shared_ptr<Statement>> stmts;
    std::shared_ptr<Expression> pred;

    RepeatStatement(StatementList *, Expression *);

    ~RepeatStatement() override = default;

    void print() const override;
};