#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "src/AST/ASTNode.hpp"
#include "src/AST/Types/Type.hpp"

struct TypeDeclaration : ASTNode {
    using member = std::pair<std::string, std::shared_ptr<Type>>;
    std::vector<member> members;

    TypeDeclaration(char *, Type *);

    TypeDeclaration(TypeDeclaration *, char *, Type *);

    ~TypeDeclaration() override = default;

    void print() const override;

    void fold_constants() override;

    void emit(SymbolTable &table) override;
};