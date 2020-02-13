#pragma once

#include <vector>
#include <memory>

#include "Statement.hpp"
#include "FrontEnd/AST/Expressions/ExpressionList.hpp"

struct WriteStatement : Statement {
    std::vector<std::unique_ptr<Expression>> args;

    explicit WriteStatement(ExpressionList *);

    ~WriteStatement() override = default;

    void accept(Visitor &) override;
};