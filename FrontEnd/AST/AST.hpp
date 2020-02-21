#pragma once

#include <memory>

#include "FrontEnd/AST/Block.hpp"
#include "PrettyPrintVisitor.hpp"

struct AST {
    static std::unique_ptr<AST> main;

    std::unique_ptr<Block> type;

    explicit AST(Block *);

    ~AST() = default;

    void prettyPrint();
};
