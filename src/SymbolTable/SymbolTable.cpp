#include "SymbolTable.hpp"

#include <iostream>
#include <utility>

SymbolTable::SymbolTable() {
    //Initialize global scope
    scopes.emplace_back();
}

void SymbolTable::addVariable(const std::string &id, std::shared_ptr<Type> type) {
    if (scopes.size() == 1) {
        //Global variable
        scopes[0].addVariable(id, type, "$gp");
    } else {
        //Local variable
        scopes[1].addVariable(id, type, "$sp");
    }
}

void SymbolTable::Scope::addVariable(const std::string &id, std::shared_ptr<Type> type, std::string base) {
    variables[id] = Variable(id, std::move(type), std::move(base), varSize);
    varSize += 4;//TODO: support for other sizes
}

void SymbolTable::addConstant(const std::string &id, std::shared_ptr<Expression> expr) {
    scopes.back().addConstant(id, std::move(expr));
}

void SymbolTable::Scope::addConstant(const std::string &id, std::shared_ptr<Expression> expr) {
    this->constants[id] = std::move(expr);
}

void SymbolTable::addType(const std::string &id, std::shared_ptr<Type> type) {
    if (scopes.size() == 1) {
        //Global variable
        scopes[0].types[id] = std::move(type);
    } else {
        //Local variable
        scopes[1].types[id] = std::move(type);
    }
}

const Variable &SymbolTable::lookupVariable(const std::string &id) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); it++) {
        if (it->variables.find(id) != it->variables.end()) {
            return it->variables[id];
        }
    }
    std::cerr << "Variable " << id << " has not been declared\n";
    std::exit(4);
}

std::shared_ptr<Expression> SymbolTable::lookupConstant(const std::string &id) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); it++) {
        if (it->constants.find(id) != it->constants.end()) {
            return it->constants[id];
        }
    }
    std::cerr << "Constant " << id << " has not been declared\n";
    std::exit(4);
}

bool SymbolTable::isVariable(const std::string &id) const {
    for (const auto &scope : scopes) {
        if (scope.variables.find(id) != scope.variables.end()) {
            return true;
        }
    }
    return false;
}

bool SymbolTable::isConstant(const std::string &id) const {
    for (const auto &scope : scopes) {
        if (scope.constants.find(id) != scope.constants.end()) {
            return true;
        }
    }
    return false;
}
