#pragma once

#include <iostream>

#include "AST.hpp"

class ConstantDecl : public ASTNode {
private:
    std::string id;
    long val;

public:
    ConstantDecl(char *id, int val);

    explicit ConstantDecl(ASTNode *);
    void echo();
};
