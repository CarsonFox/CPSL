#include "SuccExpression.hpp"

SuccExpression::SuccExpression(Expression *e) {
    expr = std::shared_ptr<Expression>(e);
}

void SuccExpression::print() const {
    std::cout << "SUCC(";
    expr->print();
    std::cout << ')';
}

bool SuccExpression::isConst() const {
    return expr->isConst();
}

std::optional<int> SuccExpression::try_fold() {
    const auto f = expr->try_fold();
    if (f)
        return *f + 1;
    return {};
}

std::string SuccExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    const auto exprReg = expr->emitToRegister(table, pool);
    auto destReg = pool.getRegister();

    std::cout << "addi " << destReg << ", " << exprReg << ", " << "1 #";
    this->print();
    std::cout << std::endl;

    pool.freeRegister(exprReg);
    return destReg;
}
