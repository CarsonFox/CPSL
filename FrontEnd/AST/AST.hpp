#pragma once

#include <memory>

#include "FrontEnd/AST/Declarations/Type.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<Type> type;

    explicit AST(Type *s);

    ~AST() = default;

    void prettyPrint();
};
