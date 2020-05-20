#pragma once

#include <memory>

#include "Statement.hpp"
#include "src/AST/Expressions/LValue.hpp"

struct AssignStatement : Statement {
    std::shared_ptr<LValue> lvalue;
    std::shared_ptr<Expression> expr;

    AssignStatement(LValue *, Expression *);

    ~AssignStatement() override = default;

    void print() const override;

    void fold_constants() override;
};