#pragma once

#include "src/AST/Expressions/Expression.hpp"

class SymbolTable;

struct Type : ASTNode {
    virtual int getSize(SymbolTable &) {
        std::cerr << "getSize unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }

    virtual Expression::type getTypeEnum(SymbolTable &) const {
        std::cerr << "getTypeEnum unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(13);
    }
};