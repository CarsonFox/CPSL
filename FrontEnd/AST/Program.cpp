#include "Program.hpp"

#include "Util.hpp"

std::shared_ptr<Program> Program::main;

void Program::prettyPrint() {
    if (constDecl) {
        constDecl->print();
        newline();
    }
    if (typeDecl) {
        typeDecl->print();
        newline();
    }
    if (varDecl) {
        varDecl->print();
        newline();
    }

    for (const auto &s: subroutines) {
        s->print();
        newline();
    }

    if (block)
        block->print();
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

void Program::fold_constants() {
    if (constDecl)
        constDecl->fold_constants();
    if (typeDecl)
        typeDecl->fold_constants();
    if (varDecl)
        varDecl->fold_constants();

    for (auto &sub: subroutines)
        sub->fold_constants();

    if (block)
        block->fold_constants();
}
