#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "FrontEnd/AST/ASTNode.hpp"
#include "Type.hpp"

struct TypeDeclaration : ASTNode {
    using member = std::pair<std::string, std::unique_ptr<Type>>;
    std::vector<member> members;

    TypeDeclaration(char *, Type *);

    TypeDeclaration(TypeDeclaration *, char *, Type *);

    ~TypeDeclaration() override = default;

    void accept(Visitor &) override;
};