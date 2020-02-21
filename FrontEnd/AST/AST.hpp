#pragma once

#include <memory>

#include "FrontEnd/AST/Declarations/Body.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<Body> type;

    explicit AST(Body *);

    ~AST() = default;

    void prettyPrint();
};
