#include "BuiltinType.hpp"

BuiltinType::BuiltinType(Expression::type t) : type(t) {}

//All of the builtins fit in one word
int BuiltinType::getSize(SymbolTable &) {
    return 4;
}

void BuiltinType::print() const {
    std::cerr << "Tried to print builtin type. This should never happen!\n";
    std::exit(8);
}

Expression::type BuiltinType::getTypeEnum(SymbolTable &) const {
    return type;
}
