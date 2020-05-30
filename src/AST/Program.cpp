#include "Program.hpp"

#include "Util.hpp"
#include "src/Labels.hpp"

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

void Program::emit() {
    /*
     * Programs are assumed to be syntactically correct.
     * This includes assuming no duplicate procedure/function identifiers.
     * Along with making no attempts to optimize the assembly, this simplifies things a lot.
     */

    SymbolTable symbolTable;
    RegisterPool registerPool;

    if (varDecl) {
        varDecl->emit(symbolTable, registerPool);
    }
    if (constDecl) {
        constDecl->emit(symbolTable, registerPool);
    }
    if (typeDecl) {
        typeDecl->emit(symbolTable, registerPool);
    }

    std::cout << ".text\n\n";

    std::cout << "j main #Begin with main entry point\n\n";

    for (auto &sub: subroutines) {
        sub->emit(symbolTable, registerPool);
    }

    std::cout << "main:\n";

    if (block) {
        block->emit(symbolTable, registerPool);
    }

    std::cout << "li $v0, 10\n" << "syscall\n\n";

    std::cout << ".data\n";
    Labels::emitStrings();
}
