#include "IdentifierExpression.hpp"

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

std::string IdentifierExpression::emitLocationToRegister(SymbolTable &table, RegisterPool &pool) {
    if (!table.isVariable(id)) {
        std::cerr << "Constants do not have a memory location!\n";
        std::exit(9);
    }

    auto reg = pool.getRegister();
    const auto var = table.lookupVariable(id);
    const auto base = var.getBase();
    const int offset = var.getOffset();

    std::cout << "addi " << reg << ", " << base << ", " << offset << " #Load location of " << id << std::endl;

    return reg;
}

std::shared_ptr<Type> IdentifierExpression::getConcreteType(SymbolTable &table) {
    return table.lookupVariable(id).getConcreteType();
}

Expression::type IdentifierExpression::getType(SymbolTable &table) {
    if (table.isConstant(id)) {
        return table.lookupConstant(id)->getType(table);
    }

    //TODO fix this
    return integral;
}
