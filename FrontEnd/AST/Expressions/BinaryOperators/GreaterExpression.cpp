#include "GreaterExpression.hpp"

GreaterExpression::GreaterExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void GreaterExpression::print() const {
    left->print();
    std::cout << " > ";
    right->print();
}
