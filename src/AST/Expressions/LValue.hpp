#pragma once

#include <memory>

#include "Expression.hpp"

struct Type;

struct LValue : Expression {
    virtual std::string getLocation(SymbolTable &) {
        std::cerr << "getLocation unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }

    virtual std::string emitLocationToRegister(SymbolTable &, RegisterPool &) {
        std::cerr << "getLocation unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }

    virtual std::shared_ptr<Type> getConcreteType(SymbolTable &) {
        std::cerr << "getConcreteType unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }
};