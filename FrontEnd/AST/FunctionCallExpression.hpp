#pragma once

#include "ExpressionList.hpp"

struct FunctionCallExpression : Expression {
    std::string id;
    std::vector<std::unique_ptr<Expression>> args;

    FunctionCallExpression(char *, ExpressionList *);

    ~FunctionCallExpression() override = default;

    void accept(Visitor &) override;
};