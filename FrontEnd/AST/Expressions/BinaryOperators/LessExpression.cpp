#include "LessExpression.hpp"

LessExpression::LessExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void LessExpression::print() const {
    left->print();
    std::cout << " < ";
    right->print();
}
