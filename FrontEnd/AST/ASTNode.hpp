#pragma once

//Every AST node prints itself
#include <iostream>

struct ASTNode {
    virtual ~ASTNode() = default;

    virtual void print() const = 0;

    virtual void fold_constants() {}

    virtual void emit() {
        std::cerr << "Emit unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }
};