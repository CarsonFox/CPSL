#include "GreaterEqualExpression.hpp"

GreaterEqualExpression::GreaterEqualExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void GreaterEqualExpression::print() const {
    left->print();
    std::cout << " >= ";
    right->print();
}
