#include "LiteralExpression.hpp"

LiteralExpression::LiteralExpression(int x) : value(x) {}

void LiteralExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
