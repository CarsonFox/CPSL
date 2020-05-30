#pragma once

#include "src/AST/ASTNode.hpp"

#include "FormalParameters.hpp"
#include "Body.hpp"

struct Subroutine : ASTNode {
    std::string id;
    std::shared_ptr<FormalParameters> param;
    std::shared_ptr<Body> body;

    Subroutine(char *, FormalParameters *);

    Subroutine(char *, FormalParameters *, Body *);

    bool isForward() const;

    void emit(SymbolTable &table, RegisterPool &pool) override;

private:
    void saveParameters(SymbolTable &table, RegisterPool &pool);
};