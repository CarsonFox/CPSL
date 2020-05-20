#include "IdentifierExpression.hpp"

#include <utility>

IdentifierExpression::IdentifierExpression(char *s) : id(s) {
    free(s);
}

IdentifierExpression::IdentifierExpression(std::string s) : id(std::move(s)) {
}

void IdentifierExpression::print() const {
    std::cout << id;
}

bool IdentifierExpression::isConst() const {
    //TODO: This will probably be replaced by a symbol table lookup.
    return false;
}
