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

void ConstDeclaration::print() const {
    std::cout << "CONST ";
    for (const auto &[id, expr] : members) {
        std::cout << id << " = ";
        expr->print();
        std::cout << "; ";
    }
}