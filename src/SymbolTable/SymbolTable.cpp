#include "SymbolTable.hpp"

#include <iostream>

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
    variables[id] = Variable(id, type, base);
}

void SymbolTable::addType(std::string id, std::shared_ptr<Type> type) {
    SymbolTableType s_type(type);

    if (scopes.size() == 1) {
        //Global variable
        scopes[0].types[id] = s_type;
    } else {
        //Local variable
        scopes[1].types[id] = s_type;
    }
}

const Variable &SymbolTable::lookupVariable(const std::string &id) {
    if (scopes.size() > 1) {
        auto var = scopes[1].variables.find(id);
        if (var != scopes[1].variables.end()) {
            return scopes[1].variables[id];
        }
    }

    auto var = scopes[0].variables.find(id);
    if (var != scopes[0].variables.end()) {
        return scopes[0].variables[id];
    } else {
        std::cerr << "Variable " << id << " has not been declared\n";
        std::exit(4);
    }
}

