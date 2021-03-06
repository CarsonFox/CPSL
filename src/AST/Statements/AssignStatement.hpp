#pragma once

#include <memory>

#include "Statement.hpp"
#include "src/AST/Expressions/LValue.hpp"

struct AssignStatement : Statement {
    std::shared_ptr<LValue> lvalue;
    std::shared_ptr<Expression> expr;

    AssignStatement(LValue *, Expression *);

    AssignStatement(LValue *, std::shared_ptr<Expression>);

    ~AssignStatement() override = default;

    void print() const override;

    void fold_constants() override;

    void emit(SymbolTable &table, RegisterPool &pool) override;
};