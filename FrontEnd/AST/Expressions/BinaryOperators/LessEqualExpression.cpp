#include "LessEqualExpression.hpp"

LessEqualExpression::LessEqualExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void LessEqualExpression::print() const {
    left->print();
    std::cout << " <= ";
    right->print();
}
