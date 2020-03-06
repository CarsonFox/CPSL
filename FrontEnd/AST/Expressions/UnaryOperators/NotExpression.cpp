#include "NotExpression.hpp"

NotExpression::NotExpression(Expression *e) : UnaryOpExpression(e) {}

void NotExpression::print() const {
    std::cout << '~';
    expr->print();
}

std::optional<int> NotExpression::try_fold() {
    const auto f = expr->try_fold();
    if (f)
        return !*f;
    return {};
}

bool NotExpression::isConst() const {
    return expr->isConst();
}
