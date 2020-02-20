#pragma once

#include <memory>

#include "Declarations/ConstDeclaration.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<ConstDeclaration> type;

    explicit AST(ConstDeclaration *);

    ~AST() = default;

    void prettyPrint();
};
