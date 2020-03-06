#include "ParenthesisExpression.hpp"

ParenthesisExpression::ParenthesisExpression(Expression *e) : expr(e) {}

void ParenthesisExpression::print() const {
    std::cout << '(';
    expr->print();
    std::cout << ')';
}

bool ParenthesisExpression::isConst() const {
    return expr->isConst();
}
