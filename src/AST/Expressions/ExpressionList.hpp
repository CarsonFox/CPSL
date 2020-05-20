#pragma once

#include <vector>
#include <memory>

#include "Expression.hpp"

/*
 * Meta-class that helps parse a list of Expressions left-recursive style.
 * Yields a vector once the list's done parsing.
 */
class ExpressionList {
private:
    ExpressionList *left;
    Expression *right;

public:
    ExpressionList(ExpressionList *, Expression *);

    ~ExpressionList();

    std::vector<std::shared_ptr<Expression>> toVector();
};