#include <src/AST/Expressions/LiteralExpression.hpp>
#include "LessExpression.hpp"

LessExpression::LessExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

LessExpression::LessExpression(Expression *l, std::shared_ptr<Expression> r) : BinaryOpExpression(l, nullptr) {
    right = std::move(r);
}

void LessExpression::print() const {
    left->print();
    std::cout << " < ";
    right->print();
}

std::optional<int> LessExpression::try_fold() {
    const auto l = left->try_fold(), r = right->try_fold();

    if (l && r)
        return *l < *r;

    if (l)
        left = std::shared_ptr<Expression>(new LiteralExpression(*l));
    if (r)
        right = std::shared_ptr<Expression>(new LiteralExpression(*r));

    return {};
}

std::string LessExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    auto reg1 = left->emitToRegister(table, pool);
    const auto reg2 = right->emitToRegister(table, pool);

    std::cout << "slt " << reg1 << ", " << reg1 << ", " << reg2 << " #";
    this->print();
    std::cout << std::endl;

    pool.freeRegister(reg2);
    return reg1;
}
