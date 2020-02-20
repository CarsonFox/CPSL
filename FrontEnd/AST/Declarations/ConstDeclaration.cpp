#include "ConstDeclaration.hpp"

ConstDeclaration::ConstDeclaration(char *s, Type *t) {
    members.emplace_back(s, t);
    free(s);
}

ConstDeclaration::ConstDeclaration(ConstDeclaration *left, char *s, Type *t) {
    members = std::move(left->members);
    members.emplace_back(s, t);
    delete left;
    free(s);
}

void ConstDeclaration::accept(Visitor &visitor) {
    visitor.visit(this);
}
