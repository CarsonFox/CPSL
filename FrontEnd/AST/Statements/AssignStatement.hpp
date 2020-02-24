#pragma once

#include <memory>

#include "Statement.hpp"
#include "FrontEnd/AST/Expressions/LValue.hpp"

struct AssignStatement : Statement {
    std::unique_ptr<LValue> lvalue;
    std::unique_ptr<Expression> expr;

    AssignStatement(LValue *, Expression *);

    ~AssignStatement() override = default;

    void print() const override;
};