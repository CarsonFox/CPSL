#pragma once

#include <iostream>

#include "AST.hpp"

class ConstantDecl : public ASTNode {
public:
    ConstantDecl() = default;

    explicit ConstantDecl(ASTNode *);

    void echo();
};
