#include "NegExpression.hpp"

NegExpression::NegExpression(Expression *e) : UnaryOpExpression(e) {}

void NegExpression::print() const {
    std::cout << '-';
    expr->print();
}

std::optional<int> NegExpression::try_fold() const {
    const auto f = expr->try_fold();
    if (f)
        return -*f;
    return {};
}

bool NegExpression::isConst() const {
    return UnaryOpExpression::isConst();
}
