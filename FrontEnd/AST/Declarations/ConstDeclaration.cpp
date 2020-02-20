#include "ConstDeclaration.hpp"

ConstDeclaration::ConstDeclaration(char *s, Expression *e) {
    members.emplace_back(s, e);
    free(s);
}

ConstDeclaration::ConstDeclaration(ConstDeclaration *left, char *s, Expression *e) {
    members = std::move(left->members);
    members.emplace_back(s, e);
    delete left;
    free(s);
}

void ConstDeclaration::accept(Visitor &visitor) {
    visitor.visit(this);
}
