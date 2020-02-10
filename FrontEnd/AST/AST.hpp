#pragma once

#include <memory>

#include "Expression.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<Expression> expr;

    explicit AST(Expression *e);

    ~AST() = default;
};
