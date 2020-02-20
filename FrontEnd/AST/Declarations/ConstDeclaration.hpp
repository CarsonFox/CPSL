#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "FrontEnd/AST/ASTNode.hpp"
#include "Type.hpp"

struct ConstDeclaration : ASTNode {
    using member = std::pair<std::string, std::unique_ptr<Type>>;
    std::vector<member> members;

    ConstDeclaration(char *, Type *);

    ConstDeclaration(ConstDeclaration *, char *, Type *);

    ~ConstDeclaration() override = default;

    void accept(Visitor &) override;
};