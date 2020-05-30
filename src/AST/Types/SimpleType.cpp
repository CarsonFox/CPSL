#include "SimpleType.hpp"

SimpleType::SimpleType(char *s) : id(s) {
    free(s);
}

void SimpleType::print() const {
    std::cout << id;
}

int SimpleType::getSize(SymbolTable &table) {
    return table.lookupType(id)->getSize(table);
}

Expression::type SimpleType::getTypeEnum(SymbolTable &table) const {
    return table.lookupType(id)->getTypeEnum(table);
}
