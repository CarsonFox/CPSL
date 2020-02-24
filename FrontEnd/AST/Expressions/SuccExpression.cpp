#include "SuccExpression.hpp"

SuccExpression::SuccExpression(Expression *e) {
    expr = std::unique_ptr<Expression>(e);
}

void SuccExpression::print() const {
    std::cout << "SUCC(";
    expr->print();
    std::cout << ')';
}

bool SuccExpression::isConst() const {
    return expr->isConst();
}
