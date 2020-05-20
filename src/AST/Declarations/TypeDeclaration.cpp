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

void TypeDeclaration::print() const {
    std::cout << "TYPE ";
    for (const auto &[id, type]: members) {
        std::cout << id << " = ";
        type->print();
        std::cout << "; ";
    }
}

void TypeDeclaration::fold_constants() {
    for (auto &[ids, type]: members)
        type->fold_constants();
}

void TypeDeclaration::emit(SymbolTable &table) {
    for (const auto &[id, type]: members) {
        table.addType(id, type);
    }
}
