#pragma once

#include <memory>

#include "Declarations/TypeDeclaration.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<TypeDeclaration> type;

    explicit AST(TypeDeclaration *);

    ~AST() = default;

    void prettyPrint();
};
