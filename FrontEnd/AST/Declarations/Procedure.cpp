#include "Procedure.hpp"

Procedure::Procedure(char *s, FormalParameters *fp) : id(s), param(fp) {
    free(s);
}

Procedure::Procedure(char *s, FormalParameters *fp, Body *b) : id(s), param(fp), body(b) {
    free(s);
}

bool Procedure::isForward() const {
    return !body;
}

void Procedure::print() const {
    std::cout << "PROCEDURE " << id << '(';
    param->print();
    if (this->isForward())
        std::cout << "); FORWARD;";
    else {
        std::cout << ");\n";
        body->print();
        std::cout << ';';
    }
}
