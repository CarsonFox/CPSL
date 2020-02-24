#include "UnaryOpExpression.hpp"

UnaryOpExpression::UnaryOpExpression(Expression *e, UnaryOp t) : expr(e), type(t) {
}

void UnaryOpExpression::print() const {
    if (type == UnaryOp::Neg)
        std::cout << '-';
    else
        std::cout << '~';
    expr->print();
}

bool UnaryOpExpression::isConst() const {
    return expr->isConst();
}
