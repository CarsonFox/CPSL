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

void VariableDeclaration::print() const {
    std::cout << "VAR ";
    for (const auto &[ids, type] : members) {
        for (auto it = ids.begin(); it < ids.end() - 1; it++)
            std::cout << *it << ", ";
        std::cout << ids.back() << ": ";
        type->print();
        std::cout << ';';
    }
}

void VariableDeclaration::fold_constants() {
    for (auto &[ids, type]: members)
        type->fold_constants();
}

void VariableDeclaration::emit(SymbolTable &table) {
    for (const auto &[ids, type] : members) {
        for (const auto &id: ids) {
            table.addVariable(id, type);
        }
    }
}
