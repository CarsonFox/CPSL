#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "FrontEnd/AST/ASTNode.hpp"
#include "FrontEnd/AST/IdentifierList.hpp"
#include "Type.hpp"

struct VariableDeclaration : ASTNode {
    using member = std::pair<std::vector<std::string>, std::shared_ptr<Type>>;
    std::vector<member> members;

    VariableDeclaration(IdentifierList *, Type *);

    VariableDeclaration(VariableDeclaration *, IdentifierList *, Type *);

    ~VariableDeclaration() override = default;

    void print() const override;

    void fold_constants() override;
};