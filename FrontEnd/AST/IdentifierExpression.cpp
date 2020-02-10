#include "IdentifierExpression.hpp"

IdentifierExpression::IdentifierExpression(char *s) : id(s) {
    free(s);
}

void IdentifierExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
