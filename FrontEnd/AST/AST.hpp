#pragma once

#include <memory>

#include "FrontEnd/AST/Statements/Statement.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<Statement> stmt;

    explicit AST(Statement *s);

    ~AST() = default;

    void prettyPrint();
};
