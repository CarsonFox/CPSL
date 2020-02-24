#include "PredExpression.hpp"

PredExpression::PredExpression(Expression *e) : expr(e) {}

void PredExpression::print() const {
    std::cout << "PRED(";
    expr->print();
    std::cout << ')';
}

bool PredExpression::isConst() const {
    return expr->isConst();
}
