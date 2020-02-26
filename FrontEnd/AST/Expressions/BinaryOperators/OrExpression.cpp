#include "OrExpression.hpp"

OrExpression::OrExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void OrExpression::print() const {
    left->print();
    std::cout << " | ";
    right->print();
}
