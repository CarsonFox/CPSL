#include "ParenthesisExpression.hpp"

ParenthesisExpression::ParenthesisExpression(Expression *e) : expr(e) {}

void ParenthesisExpression::print() const {
    std::cout << '(';
    expr->print();
    std::cout << ')';
}

bool ParenthesisExpression::isConst() const {
    return expr->isConst();
}

std::optional<int> ParenthesisExpression::try_fold() {
    const auto folded = expr->try_fold();
    if (folded)
        return *folded;
    return {};
}

std::string ParenthesisExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    return expr->emitToRegister(table, pool);
}
