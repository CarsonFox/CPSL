#pragma once

#include <vector>
#include <memory>

#include "Statement.hpp"
#include "FrontEnd/AST/Expressions/ExpressionList.hpp"

struct WriteStatement : Statement {
    std::vector<std::shared_ptr<Expression>> args;

    explicit WriteStatement(ExpressionList *);

    ~WriteStatement() override = default;

    void print() const override;

    void fold_constants() override;
};