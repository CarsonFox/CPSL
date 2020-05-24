#include "IdentifierExpression.hpp"

#include <utility>

IdentifierExpression::IdentifierExpression(char *s) : id(s) {
    free(s);
}

IdentifierExpression::IdentifierExpression(std::string s) : id(std::move(s)) {
}

void IdentifierExpression::print() const {
    std::cout << id;
}

bool IdentifierExpression::isConst() const {
    //TODO: This will probably be replaced by a symbol table lookup.
    return false;
}

std::string IdentifierExpression::getLocation(SymbolTable &table) {
    const auto &var = table.lookupVariable(id);
    return var.getLocation();
}

std::string IdentifierExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    if (table.isVariable(this->id)) {
        auto reg = pool.getRegister();
        const auto loc = this->getLocation(table);

        std::cout << "lw " << reg << ", " << loc << " #Load " << this->id << std::endl;

        return reg;
    } else if (table.isConstant(this->id)) {
        return table.lookupConstant(this->id)->emitToRegister(table, pool);
    }
    std::cerr << this->id << " is not a variable or constant\n";
    std::exit(5);
}
