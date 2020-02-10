//
// Created by fox on 2/10/20.
//

#include "ArrayAccessExpression.hpp"

ArrayAccessExpression::ArrayAccessExpression(LValue *l, Expression *r) : left(l), right(r) {}

void ArrayAccessExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
