#include "SymbolTable.hpp"

SymbolTable::SymbolTable() {
    //Initialize global scope
    scopes.emplace_back();
}

void SymbolTable::addVariable(std::string id, std::shared_ptr<Type> type) {
    if (scopes.size() == 1) {
        //Global variable
        scopes[0].addVariable(id, type, "$gp");
    } else {
        //Local variable
        scopes[1].addVariable(id, type, "$sp");
    }
}

void SymbolTable::Scope::addVariable(std::string id, std::shared_ptr<Type> type, std::string base) {
    variables[id] = Variable();
}

void SymbolTable::addType(std::string id, std::shared_ptr<Type> type) {

}
