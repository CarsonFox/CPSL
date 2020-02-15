#pragma once

#include <memory>
#include <vector>


#include <FrontEnd/AST/Expressions/Expression.hpp>
#include "Statement.hpp"
#include "StatementList.hpp"

struct RepeatStatement : Statement {
    std::vector<std::unique_ptr<Statement>> stmts;
    std::unique_ptr<Expression> pred;

    RepeatStatement(StatementList *, Expression *);

    ~RepeatStatement() override = default;

    void accept(Visitor &) override;
};