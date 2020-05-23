#include <src/AST/Expressions/LiteralExpression.hpp>
#include "GreaterExpression.hpp"

GreaterExpression::GreaterExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void GreaterExpression::print() const {
    left->print();
    std::cout << " > ";
    right->print();
}

std::optional<int> GreaterExpression::try_fold() {
    const auto l = left->try_fold(), r = right->try_fold();

    if (l && r)
        return *l > *r;

    if (l)
        left = std::shared_ptr<Expression>(new LiteralExpression(*l));
    if (r)
        right = std::shared_ptr<Expression>(new LiteralExpression(*r));

    return {};
}

std::string GreaterExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    auto reg1 = left->emitToRegister(table, pool);
    const auto reg2 = right->emitToRegister(table, pool);

    std::cout << "sgt " << reg1 << ", " << reg1 << ", " << reg2 << " #";
    this->print();
    std::cout << std::endl;

    pool.freeRegister(reg2);
    return reg1;
}
