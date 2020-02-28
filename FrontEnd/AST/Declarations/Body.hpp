#pragma once

#include <memory>

#include "FrontEnd/AST/ASTNode.hpp"
#include "ConstDeclaration.hpp"
#include "TypeDeclaration.hpp"
#include "VariableDeclaration.hpp"
#include "Block.hpp"

struct Body : ASTNode {
    std::shared_ptr<ConstDeclaration> constDecl;
    std::shared_ptr<TypeDeclaration> typeDecl;
    std::shared_ptr<VariableDeclaration> varDecl;
    std::shared_ptr<Block> block;

    Body(ConstDeclaration *, TypeDeclaration *, VariableDeclaration *, Block *);

    ~Body() override = default;

    void print() const override;
};