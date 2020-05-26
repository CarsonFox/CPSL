#include "BuiltinType.hpp"

//All of the builtins fit in one word
int BuiltinType::getSize(SymbolTable &) {
    return 4;
}

void BuiltinType::print() const {
    std::cerr << "Tried to print builtin type. This should never happen!\n";
    std::exit(8);
}
