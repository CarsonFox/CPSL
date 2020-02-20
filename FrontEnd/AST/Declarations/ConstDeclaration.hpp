#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "FrontEnd/AST/ASTNode.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"

struct ConstDeclaration : ASTNode {
    using member = std::pair<std::string, std::unique_ptr<Expression>>;
    std::vector<member> members;

    ConstDeclaration(char *, Expression *);

    ConstDeclaration(ConstDeclaration *, char *, Expression *);

    ~ConstDeclaration() override = default;

    void accept(Visitor &) override;
};