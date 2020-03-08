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

std::optional<int> PredExpression::try_fold() {
    expr->try_fold();
    return {};
}
