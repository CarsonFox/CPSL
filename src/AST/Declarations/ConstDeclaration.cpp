#include <src/AST/Expressions/LiteralExpression.hpp>
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

void ConstDeclaration::fold_constants() {
    for (auto &[id, expr]: members) {
        const auto folded = expr->try_fold();
        if (folded)
            expr = std::shared_ptr<Expression>(new LiteralExpression(*folded));
    }
}

void ConstDeclaration::emit(SymbolTable &table, RegisterPool &) {
    for (const auto &[id, expr] : members) {
        table.addConstant(id, expr);
    }
}
