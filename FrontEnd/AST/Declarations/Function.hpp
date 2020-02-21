#pragma once

#include <memory>
#include <string>

#include "FormalParameters.hpp"
#include "Type.hpp"
#include "Body.hpp"

struct Function : ASTNode {
    std::string id;
    std::unique_ptr<FormalParameters> param;
    std::unique_ptr<Type> type;
    std::unique_ptr<Body> body;

    Function(char *, FormalParameters *, Type *);

    Function(char *, FormalParameters *, Type *, Body *);

    void accept(Visitor &) override;

    bool isForward() const;
};