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
    constDecl->fold_constants();
    typeDecl->fold_constants();
    varDecl->fold_constants();
    block->fold_constants();
}
