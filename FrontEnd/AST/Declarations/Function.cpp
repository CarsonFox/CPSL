#include "Function.hpp"

Function::Function(char *s, FormalParameters *fp, Type *t) : id(s), param(fp), type(t) {
    free(s);
}

Function::Function(char *s, FormalParameters *fp, Type *t, Body *b) : id(s), param(fp), type(t), body(b) {
    free(s);
}

void Function::accept(Visitor &visitor) {
    visitor.visit(this);
}

bool Function::isForward() const {
    return !body;
}
