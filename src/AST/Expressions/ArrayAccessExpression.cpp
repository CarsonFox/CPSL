#include "ArrayAccessExpression.hpp"

#include "src/AST/Types/ArrayType.hpp"

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

    std::cout << "li " << elementSizeReg << ", " << this->getConcreteType(table)->getSize(table)
              << " #Get array element size\n";
    std::cout << "mul " << offsetReg << ", " << offsetReg << ", " << elementSizeReg << " #Compute offset\n";

    pool.freeRegister(elementSizeReg);

    std::cout << "add " << baseLocReg << ", " << baseLocReg << ", " << offsetReg << " #Compute array access for ";
    this->print();
    std::cout << std::endl;

    pool.freeRegister(offsetReg);

    return baseLocReg;
}

std::string ArrayAccessExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    auto reg = this->emitLocationToRegister(table, pool);

    std::cout << "lw " << reg << ", (" << reg << ") #";
    this->print();
    std::cout << std::endl;

    return reg;
}

std::shared_ptr<Type> ArrayAccessExpression::getConcreteType(SymbolTable &table) {
    const auto arr = std::dynamic_pointer_cast<ArrayType>(left->getConcreteType(table));

    if (!arr) {
        std::cout << "Cannot access non-array type ";
        left->print();
        std::cout << std::endl;
        std::exit(10);
    }

    return arr->type;
}

Expression::type ArrayAccessExpression::getType(SymbolTable &table) {
    return getConcreteType(table)->getTypeEnum(table);
}
