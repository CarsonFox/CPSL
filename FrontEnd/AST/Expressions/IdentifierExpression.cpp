#include "IdentifierExpression.hpp"

IdentifierExpression::IdentifierExpression(char *s) : id(s) {
    free(s);
}

void IdentifierExpression::print() const {
    std::cout << id;
}

bool IdentifierExpression::isConst() const {
    //TODO: This will probably be replaced by a symbol table lookup.
    return false;
}
