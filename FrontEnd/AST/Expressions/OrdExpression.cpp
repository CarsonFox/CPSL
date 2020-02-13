//
// Created by fox on 2/9/20.
//

#include "OrdExpression.hpp"

OrdExpression::OrdExpression(Expression *e) : expr(e) {}

void OrdExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
