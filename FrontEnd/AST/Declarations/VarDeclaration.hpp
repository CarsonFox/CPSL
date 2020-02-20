#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "FrontEnd/AST/ASTNode.hpp"
#include "FrontEnd/AST/IdentifierList.hpp"
#include "Type.hpp"

struct VarDeclaration : ASTNode {
    using member = std::pair<std::vector<std::string>, std::unique_ptr<Type>>;
    std::vector<member> members;

    VarDeclaration(IdentifierList *, Type *);

    VarDeclaration(VarDeclaration *, IdentifierList *, Type *);

    ~VarDeclaration() override = default;

    void accept(Visitor &) override;
};