#include "ModExpression.hpp"

ModExpression::ModExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void ModExpression::print() const {
    left->print();
    std::cout << " % ";
    right->print();
}
