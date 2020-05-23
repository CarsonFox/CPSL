#include "NotExpression.hpp"

NotExpression::NotExpression(Expression *e) : UnaryOpExpression(e) {}

void NotExpression::print() const {
    std::cout << '~';
    expr->print();
}

std::optional<int> NotExpression::try_fold() {
    const auto f = expr->try_fold();
    if (f)
        return !*f;
    return {};
}

bool NotExpression::isConst() const {
    return expr->isConst();
}


/*
 * If this is meant to work like c/c++, this can be accomplished by using seq $r, $zero.
 */
std::string NotExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    auto reg = expr->emitToRegister(table, pool);

    std::cout << "seq " << reg << ", " << reg << ", $zero #";
    this->print();
    std::cout << std::endl;

    return reg;
}
