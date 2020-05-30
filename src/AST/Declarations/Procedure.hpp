#pragma once

#include <memory>
#include <string>

#include "Subroutine.hpp"
#include "FormalParameters.hpp"
#include "Body.hpp"

struct Procedure : Subroutine {
    std::string id;
    std::shared_ptr<FormalParameters> param;
    std::shared_ptr<Body> body;

    Procedure(char *, FormalParameters *);

    Procedure(char *, FormalParameters *, Body *);

    ~Procedure() override = default;

    void print() const override;

    bool isForward() const override;

    void fold_constants() override;

    void emit(SymbolTable &table, RegisterPool &pool) override;

private:
    void saveParameters(SymbolTable &table, RegisterPool &pool);
};