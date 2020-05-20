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
    const auto f = expr->try_fold();
    if (f)
        return *f - 1;
    return {};
}
