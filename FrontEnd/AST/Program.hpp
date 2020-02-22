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
    static std::unique_ptr<Program> main;

    std::unique_ptr<ConstDeclaration> constDecl;
    std::unique_ptr<TypeDeclaration> typeDecl;
    std::unique_ptr<VariableDeclaration> varDecl;
    std::vector<std::unique_ptr<ASTNode>> subroutines;
    std::unique_ptr<Block> block;

    Program() = default;

    Program(Program *, Subroutine *);

    Program(ConstDeclaration *, TypeDeclaration *, VariableDeclaration *);

    Program(Program *, Program *, Block *);

    ~Program() = default;

    void prettyPrint();
};
