#include "UnaryOpExpression.hpp"

UnaryOpExpression::UnaryOpExpression(Expression *e) : expr(e) {
}

bool UnaryOpExpression::isConst() const {
    return expr->isConst();
}
