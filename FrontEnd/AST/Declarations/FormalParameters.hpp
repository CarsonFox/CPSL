#pragma once

#include <memory>
#include <vector>
#include <string>

#include "FrontEnd/AST/IdentifierList.hpp"
#include "Type.hpp"

enum ParType {
    NONE,
    VAR_T,
    REF_T,
};

struct FormalParameters : ASTNode {
    using member = std::tuple<ParType, std::vector<std::string>, std::shared_ptr<Type>>;
    std::vector<member> members;

    FormalParameters() = default;

    FormalParameters(ParType, IdentifierList *, Type *);

    FormalParameters(FormalParameters *, FormalParameters *);

    ~FormalParameters() override = default;

    void print() const override;

    void fold_constants() override;
};