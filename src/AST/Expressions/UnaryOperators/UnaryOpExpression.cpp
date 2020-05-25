#include "UnaryOpExpression.hpp"

UnaryOpExpression::UnaryOpExpression(Expression *e) : expr(e) {
}

bool UnaryOpExpression::isConst() const {
    return expr->isConst();
}

//Binary operators produce integers
Expression::type UnaryOpExpression::getType(SymbolTable &) {
    return integral;
}
