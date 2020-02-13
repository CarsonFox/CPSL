//
// Created by fox on 2/13/20.
//

#include "ParenthesisExpression.hpp"

ParenthesisExpression::ParenthesisExpression(Expression *e) : expr(e) {}

void ParenthesisExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
