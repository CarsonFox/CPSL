#pragma once

#include <memory>

#include "Declarations/VarDeclaration.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<VarDeclaration> type;

    explicit AST(VarDeclaration *);

    ~AST() = default;

    void prettyPrint();
};
