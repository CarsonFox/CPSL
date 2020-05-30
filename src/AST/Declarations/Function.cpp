#include "Function.hpp"

Function::Function(char *s, FormalParameters *fp, Type *t) : Subroutine(s, fp) {
    type = std::shared_ptr<Type>(t);
}

Function::Function(char *s, FormalParameters *fp, Type *t, Body *b) : Subroutine(s, fp, b) {
    type = std::shared_ptr<Type>(t);
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

void Function::fold_constants() {
    param->fold_constants();
    type->fold_constants();
    if (body)
        body->fold_constants();
}

void Function::emit(SymbolTable &table, RegisterPool &pool) {
    table.addFunction(id, type);
    Subroutine::emit(table, pool);
}
