#include "SubExpression.hpp"

SubExpression::SubExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void SubExpression::print() const {
    left->print();
    std::cout << " - ";
    right->print();
}
