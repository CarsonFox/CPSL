#pragma once

//Every AST node prints itself
#include <iostream>

struct ASTNode {
    virtual ~ASTNode() = default;

    virtual void print() const = 0;
};