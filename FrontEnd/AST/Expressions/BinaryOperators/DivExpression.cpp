#include "DivExpression.hpp"

DivExpression::DivExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void DivExpression::print() const {
    left->print();
    std::cout << " / ";
    right->print();
}
