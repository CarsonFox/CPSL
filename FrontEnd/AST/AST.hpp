#pragma once

#include <memory>

#include "FrontEnd/AST/Declarations/FormalParameters.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<FormalParameters> type;

    explicit AST(FormalParameters *);

    ~AST() = default;

    void prettyPrint();
};
