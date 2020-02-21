#pragma once

#include <memory>

#include "FrontEnd/AST/ASTNode.hpp"
#include "ConstDeclaration.hpp"
#include "TypeDeclaration.hpp"
#include "VariableDeclaration.hpp"
#include "Block.hpp"

struct Body : ASTNode {
    std::unique_ptr<ConstDeclaration> constDecl;
    std::unique_ptr<TypeDeclaration> typeDecl;
    std::unique_ptr<VariableDeclaration> varDecl;
    std::unique_ptr<Block> block;

    Body(ConstDeclaration *, TypeDeclaration *, VariableDeclaration *, Block *);

    ~Body() override = default;

    void accept(Visitor &) override;
};