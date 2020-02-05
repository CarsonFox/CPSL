#pragma once

#include <iostream>
#include <vector>

#include "AST.hpp"
#include "ConstantDecl.hpp"

struct Program : ASTNode {
    std::vector<ConstantDecl> constantDecls;

    Program(std::vector<ASTNode *> *);

    void prettyPrint() const override;

    ~Program() override = default;
};
