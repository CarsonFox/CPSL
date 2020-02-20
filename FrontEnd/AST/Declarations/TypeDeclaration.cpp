#include "TypeDeclaration.hpp"

TypeDeclaration::TypeDeclaration(char *s, Type *t) {
    members.emplace_back(s, t);
    free(s);
}

TypeDeclaration::TypeDeclaration(TypeDeclaration *left, char *s, Type *t) {
    members = std::move(left->members);
    members.emplace_back(s, t);
    delete left;
    free(s);
}

void TypeDeclaration::accept(Visitor &visitor) {
    visitor.visit(this);
}
