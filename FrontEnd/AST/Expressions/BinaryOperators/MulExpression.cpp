#include "MulExpression.hpp"

MulExpression::MulExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void MulExpression::print() const {
    left->print();
    std::cout << " * ";
    right->print();
}
