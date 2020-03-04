#include "BinaryOpExpression.hpp"

BinaryOpExpression::BinaryOpExpression(Expression *l, Expression *r) : left(l), right(r) {
}

bool BinaryOpExpression::isConst() const {
    return left->isConst() && right->isConst();
}
