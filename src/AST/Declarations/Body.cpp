#include "Body.hpp"

Body::Body(ConstDeclaration *c, TypeDeclaration *t, VariableDeclaration *v, Block *b)
        : constDecl(c), typeDecl(t), varDecl(v), block(b) {}

void Body::print() const {
    if (constDecl)
        constDecl->print();
    if (typeDecl)
        typeDecl->print();
    if (varDecl)
        varDecl->print();

    block->print();
}

void Body::fold_constants() {
    if (constDecl)
        constDecl->fold_constants();
    if (typeDecl)
        typeDecl->fold_constants();
    if (varDecl)
        varDecl->fold_constants();
    if (block)
        block->fold_constants();
}

void Body::emit(SymbolTable &table, RegisterPool &pool) {
    block->emit(table, pool);
}
