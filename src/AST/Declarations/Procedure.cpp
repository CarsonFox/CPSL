#include "Procedure.hpp"

Procedure::Procedure(char *s, FormalParameters *fp) : Subroutine(s, fp) {
}

Procedure::Procedure(char *s, FormalParameters *fp, Body *b) : Subroutine(s, fp, b) {
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

void Procedure::fold_constants() {
    param->fold_constants();
    if (body)
        body->fold_constants();
}