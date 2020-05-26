#pragma once

#include "src/AST/ASTNode.hpp"

class SymbolTable;

struct Type : ASTNode {
    virtual int getSize(SymbolTable &) {
        std::cerr << "getSize unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }
};