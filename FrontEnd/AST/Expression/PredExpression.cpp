#include "PredExpression.hpp"

PredExpression::PredExpression(Expression *e) : expr(e) {}

void PredExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
