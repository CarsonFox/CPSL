#include "Program.hpp"

#include "PrettyPrintVisitor.hpp"

std::unique_ptr<Program> Program::main;

void Program::prettyPrint() {
    PrettyPrintVisitor pp;
    if (constDecl)
        constDecl->accept(pp);
    if (typeDecl)
        typeDecl->accept(pp);
    if (varDecl)
        varDecl->accept(pp);

    for (auto &s: subroutines) {
        s->accept(pp);
    }

    if (block)
        block->accept(pp);
    std::cout << ".\n";
}

Program::Program(Program *left, Subroutine *s) {
    subroutines = std::move(left->subroutines);
    subroutines.emplace_back(s);
    delete left;
}

Program::Program(ConstDeclaration *c, TypeDeclaration *t, VariableDeclaration *v)
        : constDecl(c), typeDecl(t), varDecl(v) {}

Program::Program(Program *head, Program *body, Block *b) : block(b) {
    constDecl = std::move(head->constDecl);
    typeDecl = std::move(head->typeDecl);
    varDecl = std::move(head->varDecl);
    subroutines = std::move(body->subroutines);

    delete head;
    delete body;
}
