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

//TODO this does not give the expected output because it's bitwise - need to make sure ~True == False
/*
 * If this is meant to work like c/c++, this can be accomplished by using sne $r, $zero.
 */

std::string NotExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    auto reg = expr->emitToRegister(table, pool);

    std::cout << "not " << reg << ", " << reg << " #";
    this->print();
    std::cout << std::endl;

    return reg;
}
