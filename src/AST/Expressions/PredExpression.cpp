#include "PredExpression.hpp"

PredExpression::PredExpression(Expression *e) : expr(e) {}

void PredExpression::print() const {
    std::cout << "PRED(";
    expr->print();
    std::cout << ')';
}

bool PredExpression::isConst() const {
    return expr->isConst();
}

std::optional<int> PredExpression::try_fold() {
    const auto f = expr->try_fold();
    if (f)
        return *f - 1;
    return {};
}

std::string PredExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    const auto exprReg = expr->emitToRegister(table, pool);
    auto destReg = pool.getRegister();

    std::cout << "addi " << destReg << ", " << exprReg << ", " << "-1 #";
    this->print();
    std::cout << std::endl;

    pool.freeRegister(exprReg);
    return destReg;
}
