#include "NegExpression.hpp"

NegExpression::NegExpression(Expression *e) : UnaryOpExpression(e) {}

void NegExpression::print() const {
    std::cout << '-';
    expr->print();
}

std::optional<int> NegExpression::try_fold() {
    const auto f = expr->try_fold();
    if (f)
        return -*f;
    return {};
}

bool NegExpression::isConst() const {
    return UnaryOpExpression::isConst();
}

std::string NegExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    auto reg = expr->emitToRegister(table, pool);

    //0 - x == -x
    std::cout << "sub " << reg << ", $zero, " << reg << " #";
    this->print();
    std::cout << std::endl;

    return reg;
}
