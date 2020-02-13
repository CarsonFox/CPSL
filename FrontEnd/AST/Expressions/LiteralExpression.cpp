#include "LiteralExpression.hpp"

LiteralExpression::LiteralExpression(int x) : value(x) {
}

LiteralExpression::LiteralExpression(char c) : value(c) {
}

void LiteralExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
