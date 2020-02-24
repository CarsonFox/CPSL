#include "OrdExpression.hpp"

OrdExpression::OrdExpression(Expression *e) : expr(e) {}

void OrdExpression::print() const {
    std::cout << "ORD(";
    expr->print();
    std::cout << ')';
}

bool OrdExpression::isConst() const {
    return expr->isConst();
}
