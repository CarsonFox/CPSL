#pragma once

#include <iostream>
#include <vector>

#include "AST.hpp"
#include "ConstantDecl.hpp"

class Program : public ASTNode {
private:
    std::vector<ConstantDecl> constantDecls;
public:
    Program(std::vector<ASTNode *> *);

    void echo();
};
