#pragma once

#include <memory>

#include "src/AST/ASTNode.hpp"
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

    void fold_constants() override;

    void emit(SymbolTable &table, RegisterPool &pool) override;
};