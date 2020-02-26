#include "AndExpression.hpp"

AndExpression::AndExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void AndExpression::print() const {
    left->print();
    std::cout << " & ";
    right->print();
}
