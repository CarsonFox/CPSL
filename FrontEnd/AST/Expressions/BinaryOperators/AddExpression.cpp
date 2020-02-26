#include "AddExpression.hpp"

AddExpression::AddExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void AddExpression::print() const {
    left->print();
    std::cout << " + ";
    right->print();
}
