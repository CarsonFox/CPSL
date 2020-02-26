#include "EqualExpression.hpp"

EqualExpression::EqualExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void EqualExpression::print() const {
    left->print();
    std::cout << " = ";
    right->print();
}
