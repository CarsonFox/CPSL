#include "BinaryOpExpression.hpp"

const std::array<std::string, 13> opStrs{"|", "&", "=", "<>", "<", "<=", ">", ">=", "+", "-", "*", "/", "%"};

BinaryOpExpression::BinaryOpExpression(Expression *l, Expression *r, BinaryOp t) : left(l), right(r), type(t) {

}

void BinaryOpExpression::print() const {
    left->print();
    std::cout << ' ' << opStrs[type] << ' ';
    right->print();
}

bool BinaryOpExpression::isConst() const {
    return left->isConst() && right->isConst();
}
