#include "Procedure.hpp"

Procedure::Procedure(char *s, FormalParameters *fp) : id(s), param(fp) {
    free(s);
}

Procedure::Procedure(char *s, FormalParameters *fp, Body *b) : id(s), param(fp), body(b) {
    free(s);
}

void Procedure::accept(Visitor &visitor) {
    visitor.visit(this);
}

bool Procedure::isForward() const {
    return !body;
}
