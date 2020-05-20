#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Statement.hpp"
#include <src/AST/Expressions/Expression.hpp>
#include <src/AST/Expressions/ExpressionList.hpp>

struct ProcedureCallStatement : Statement {
    std::string id;
    std::vector<std::shared_ptr<Expression>> args;

    ProcedureCallStatement(char *, ExpressionList *);

    ~ProcedureCallStatement() override = default;

    void print() const override;

    void fold_constants() override;
};