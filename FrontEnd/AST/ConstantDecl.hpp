#pragma once

#include <iostream>

#include "AST.hpp"

struct ConstantDecl : ASTNode {
    std::string id;
    long val;

    ConstantDecl(char *id, int val);

    explicit ConstantDecl(ASTNode *);

    void prettyPrint() const override;

    ~ConstantDecl() override = default;
};
