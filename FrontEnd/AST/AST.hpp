#pragma once

#include <memory>

#include "FrontEnd/AST/Declarations/VariableDeclaration.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<VariableDeclaration> type;

    explicit AST(VariableDeclaration *);

    ~AST() = default;

    void prettyPrint();
};
