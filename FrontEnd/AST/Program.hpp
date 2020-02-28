#pragma once

#include <memory>
#include <vector>

#include "Declarations/Procedure.hpp"
#include "Declarations/Function.hpp"
#include "Declarations/ConstDeclaration.hpp"
#include "Declarations/TypeDeclaration.hpp"
#include "Declarations/VariableDeclaration.hpp"
#include "Declarations/Block.hpp"

struct Program {
    static std::shared_ptr<Program> main;

    std::shared_ptr<ConstDeclaration> constDecl;
    std::shared_ptr<TypeDeclaration> typeDecl;
    std::shared_ptr<VariableDeclaration> varDecl;
    std::vector<std::shared_ptr<ASTNode>> subroutines;
    std::shared_ptr<Block> block;

    Program() = default;

    Program(Program *, Subroutine *);

    Program(ConstDeclaration *, TypeDeclaration *, VariableDeclaration *);

    Program(Program *, Program *, Block *);

    ~Program() = default;

    void prettyPrint();
};
