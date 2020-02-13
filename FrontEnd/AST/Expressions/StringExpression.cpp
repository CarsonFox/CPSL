#include "StringExpression.hpp"

StringExpression::StringExpression(char *s) : value(s) {
    free(s);
//Trim off the double quotes for convenience.
//Easier to do here than in the parser.
    value = value.substr(1, value.size() - 2);
}

void StringExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}
