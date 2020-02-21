#include "Body.hpp"

Body::Body(ConstDeclaration *c, TypeDeclaration *t, VariableDeclaration *v, Block *b)
        : constDecl(c), typeDecl(t), varDecl(v), block(b) {}

void Body::accept(Visitor &visitor) {
    visitor.visit(this);
}
