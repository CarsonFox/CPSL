#include "StringExpression.hpp"

#include "src/Labels.hpp"

StringExpression::StringExpression(char *s) : value(s) {
    free(s);
}

void StringExpression::print() const {
    std::cout << value;
}

bool StringExpression::isConst() const {
    return true;
}

std::string StringExpression::emitToRegister(SymbolTable &, RegisterPool &pool) {
    auto reg = pool.getRegister();
    const auto label = Labels::getStringLabel(this->value);

    std::cout << "la " << reg << ", " << label << " #Load string " << this->value << std::endl;

    return reg;
}
