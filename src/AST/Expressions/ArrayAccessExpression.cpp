#include "ArrayAccessExpression.hpp"

ArrayAccessExpression::ArrayAccessExpression(LValue *l, Expression *r) : left(l), right(r) {}

void ArrayAccessExpression::print() const {
    left->print();
    std::cout << '[';
    right->print();
    std::cout << ']';
}

bool ArrayAccessExpression::isConst() const {
    return false;
}

std::optional<int> ArrayAccessExpression::try_fold() {
    right->try_fold();
    return {};
}

std::string ArrayAccessExpression::emitLocationToRegister(SymbolTable &table, RegisterPool &pool) {
    auto baseLocReg = left->emitLocationToRegister(table, pool);
    const auto offsetReg = right->emitToRegister(table, pool);
    const auto elementSizeReg = pool.getRegister();

    //TODO fix: lvalues must report their type, so we can get the size of an array's elements
    std::cout << "li " << elementSizeReg << ", " << 4 << " #Get array element size\n";
    std::cout << "mul " << offsetReg << ", " << offsetReg << ", " << elementSizeReg << " #Compute offset\n";

    pool.freeRegister(elementSizeReg);

    std::cout << "add " << baseLocReg << ", " << baseLocReg << ", " << offsetReg << " #Compute array access for ";
    this->print();
    std::cout << std::endl;

    pool.freeRegister(offsetReg);

    return baseLocReg;
}
