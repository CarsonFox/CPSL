#pragma once

#include <memory>

#include "FrontEnd/AST/Declarations/Function.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<Function> type;

    explicit AST(Function *);

    ~AST() = default;

    void prettyPrint();
};
