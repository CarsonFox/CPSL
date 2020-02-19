
#include "SimpleType.hpp"

SimpleType::SimpleType(char *s) : id(s) {
    free(s);
}

void SimpleType::accept(Visitor &visitor) {
    visitor.visit(this);
}
