#include "PredExpression.hpp"

#include "UnaryOperators/NotExpression.hpp"

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
    const auto type = expr->getType(table);

    if (type == Expression::integral || type == Expression::character) {
        const auto exprReg = expr->emitToRegister(table, pool);
        auto destReg = pool.getRegister();

        std::cout << "addi " << destReg << ", " << exprReg << ", " << "-1 #";
        this->print();
        std::cout << std::endl;

        pool.freeRegister(exprReg);
        return destReg;
    } else if (type == Expression::boolean) {
        auto reg = expr->emitToRegister(table, pool);

        std::cout << "seq " << reg << ", " << reg << ", $zero #";
        this->print();
        std::cout << std::endl;

        return reg;
    } else {
        std::cout << "Pred undefined for ";
        expr->print();
        std::cout << std::endl;
        std::exit(12);
    }
}

Expression::type PredExpression::getType(SymbolTable &table) {
    return expr->getType(table);
}
