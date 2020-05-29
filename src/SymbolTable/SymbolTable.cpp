#include "SymbolTable.hpp"

#include <iostream>

#include "src/AST/Types/BuiltinType.hpp"
#include "src/AST/Expressions/LiteralExpression.hpp"

SymbolTable::SymbolTable() {
    //Initialize global scope
    scopes.emplace_back();

    //Initialize builtin types
    std::shared_ptr<Type> builtin(new BuiltinType());
    addType("integer", builtin);
    addType("INTEGER", builtin);
    addType("char", builtin);
    addType("CHAR", builtin);
    addType("boolean", builtin);
    addType("BOOLEAN", builtin);
    addType("string", builtin);
    addType("STRING", builtin);

    //Initialize builtin constants
    std::shared_ptr<Expression> true_expr(new LiteralExpression(1));
    addConstant("true", true_expr);
    addConstant("TRUE", true_expr);

    std::shared_ptr<Expression> false_expr(new LiteralExpression(0));
    addConstant("false", false_expr);
    addConstant("FALSE", false_expr);
}

void SymbolTable::addVariable(const std::string &id, std::shared_ptr<Type> type) {
    if (scopes.size() == 1) {
        //Global variable
        scopes[0].addVariable(id, type, "$gp", type->getSize(*this));
    } else {
        //Local variable
        scopes[1].addVariable(id, type, "$sp", type->getSize(*this));
    }
}

void SymbolTable::Scope::addVariable(const std::string &id, std::shared_ptr<Type> type, std::string base, int size) {
    variables[id] = Variable(id, std::move(type), std::move(base), varSize);
    varSize += size;
}

void SymbolTable::addConstant(const std::string &id, std::shared_ptr<Expression> expr) {
    scopes.back().addConstant(id, std::move(expr));
}

void SymbolTable::Scope::addConstant(const std::string &id, std::shared_ptr<Expression> expr) {
    this->constants[id] = std::move(expr);
}

void SymbolTable::addType(const std::string &id, std::shared_ptr<Type> type) {
    scopes.back().addType(id, type);
}

void SymbolTable::Scope::addType(const std::string &id, std::shared_ptr<Type> type) {
    types[id] = std::move(type);
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

std::shared_ptr<Type> SymbolTable::lookupType(const std::string &id) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); it++) {
        if (it->types.find(id) != it->types.end()) {
            return it->types[id];
        }
    }
    std::cerr << "Type " << id << " has not been declared\n";
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

void SymbolTable::pushScope() {
    scopes.emplace_back();
}

void SymbolTable::popScope() {
    scopes.pop_back();
}
