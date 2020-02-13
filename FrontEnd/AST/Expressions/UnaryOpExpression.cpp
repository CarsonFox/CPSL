#include "UnaryOpExpression.hpp"

UnaryOpExpression::UnaryOpExpression(Expression *e, UnaryOp t) : expr(e), type(t) {
}

void UnaryOpExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}