#include "Function.hpp"

Function::Function(char *s, FormalParameters *fp, Type *t) : id(s), param(fp), type(t) {
    free(s);
}

Function::Function(char *s, FormalParameters *fp, Type *t, Body *b) : id(s), param(fp), type(t), body(b) {
    free(s);
}

bool Function::isForward() const {
    return !body;
}

void Function::print() const {
    std::cout << "FUNCTION " << id << '(';
    param->print();

    std::cout << ") : ";
    type->print();
    std::cout << "; ";

    if (this->isForward())
        std::cout << "FORWARD;";
    else {
        std::cout << '\n';
        body->print();
        std::cout << ';';
    }
}
