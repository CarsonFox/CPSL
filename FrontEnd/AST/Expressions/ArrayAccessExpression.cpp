#include "ArrayAccessExpression.hpp"

ArrayAccessExpression::ArrayAccessExpression(LValue *l, Expression *r) : left(l), right(r) {}

void ArrayAccessExpression::print() const {
    left->print();
    std::cout << '[';
    right->print();
    std::cout << ']';
}

bool ArrayAccessExpression::isConst() const {
    return false;
}

std::optional<int> ArrayAccessExpression::try_fold() {
    right->try_fold();
    return {};
}
