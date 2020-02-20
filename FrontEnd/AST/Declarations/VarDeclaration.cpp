#include "VarDeclaration.hpp"

VarDeclaration::VarDeclaration(IdentifierList *l, Type *t) {
    members.emplace_back(std::move(l->list), t);
    delete l;
}

VarDeclaration::VarDeclaration(VarDeclaration *left, IdentifierList *l, Type *t) {
    members = std::move(left->members);
    members.emplace_back(std::move(l->list), t);
    delete left;
    delete l;
}

void VarDeclaration::accept(Visitor &visitor) {
    visitor.visit(this);
}
