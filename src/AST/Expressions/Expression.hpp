#pragma once

#include <optional>

#include "src/AST/ASTNode.hpp"

class SymbolTable;

struct Expression : ASTNode {
    //The spaghetti grows...
    enum type {
        integral,
        character,
        string,
        userDefined,
    };

    virtual bool isConst() const = 0;

    virtual std::optional<int> try_fold() {
        return {};
    }

    virtual std::string emitToRegister(SymbolTable &, RegisterPool &) {
        std::cerr << "Emit to register unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }

    virtual type getType(SymbolTable &) {
        std::cerr << "getType unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }
};