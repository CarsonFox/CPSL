#include "BinaryOpExpression.hpp"

BinaryOpExpression::BinaryOpExpression(Expression *l, Expression *r) : left(l), right(r) {
}

bool BinaryOpExpression::isConst() const {
    return left->isConst() && right->isConst();
}

//All binary operators produce either integers or booleans, which can be considered integers
Expression::type BinaryOpExpression::getType(SymbolTable &) {
    return integral;
}
