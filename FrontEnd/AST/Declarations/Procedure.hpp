#pragma once

#include <memory>
#include <string>

#include "FormalParameters.hpp"
#include "Body.hpp"

struct Procedure : ASTNode {
    std::string id;
    std::unique_ptr<FormalParameters> param;
    std::unique_ptr<Body> body;

    Procedure(char *, FormalParameters *);

    Procedure(char *, FormalParameters *, Body *);

    void accept(Visitor &) override;

    bool isForward() const;
};