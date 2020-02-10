#include "RecordAccessExpression.hpp"

RecordAccessExpression::RecordAccessExpression(LValue *l, char *r) : left(l), right(r) {
    free(r);
}

void RecordAccessExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
