#pragma once

#include <memory>

#include "FrontEnd/AST/Declarations/Procedure.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<Procedure> type;

    explicit AST(Procedure *);

    ~AST() = default;

    void prettyPrint();
};
