#include "SuccExpression.hpp"

SuccExpression::SuccExpression(Expression *e) {
    expr = std::unique_ptr<Expression>(e);
}

void SuccExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
