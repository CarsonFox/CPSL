#include "StopStatement.hpp"

void StopStatement::print() const {
    std::cout << "STOP";
}

void StopStatement::emit(SymbolTable &, RegisterPool &) {
    std::cout << "li $v0, 10\n" << "syscall\n\n";
}
