#include "NotEqualExpression.hpp"

NotEqualExpression::NotEqualExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void NotEqualExpression::print() const {
    left->print();
    std::cout << " <> ";
    right->print();
}
