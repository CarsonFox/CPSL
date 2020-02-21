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
    using member = std::tuple<ParType, std::vector<std::string>, std::unique_ptr<Type>>;
    std::vector<member> members;

    FormalParameters(ParType, IdentifierList *, Type *);

    FormalParameters(FormalParameters *, FormalParameters *);

    ~FormalParameters() override = default;

    void accept(Visitor &) override;
};