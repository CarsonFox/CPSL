#include "VariableDeclaration.hpp"

VariableDeclaration::VariableDeclaration(IdentifierList *l, Type *t) {
    members.emplace_back(std::move(l->list), t);
    delete l;
}

VariableDeclaration::VariableDeclaration(VariableDeclaration *left, IdentifierList *l, Type *t) {
    members = std::move(left->members);
    members.emplace_back(std::move(l->list), t);
    delete left;
    delete l;
}

void VariableDeclaration::accept(Visitor &visitor) {
    visitor.visit(this);
}
