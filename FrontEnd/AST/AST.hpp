#pragma once

#include <memory>

#include "FrontEnd/AST/Expression/ExpressionList.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::vector<std::unique_ptr<Expression>> exprs;

    explicit AST(ExpressionList *e);

    ~AST() = default;

    void prettyPrint();
};
