#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Statement.hpp"
#include <FrontEnd/AST/Expressions/Expression.hpp>
#include <FrontEnd/AST/Expressions/ExpressionList.hpp>

struct ProcedureCallStatement : Statement {
    std::string id;
    std::vector<std::unique_ptr<Expression>> args;

    ProcedureCallStatement(char *, ExpressionList *);

    ~ProcedureCallStatement() override = default;

    void print() const override;
};