#pragma once

#include <memory>
#include <string>

#include "Subroutine.hpp"
#include "FormalParameters.hpp"
#include "Type.hpp"
#include "Body.hpp"

struct Function : Subroutine {
    std::string id;
    std::shared_ptr<FormalParameters> param;
    std::shared_ptr<Type> type;
    std::shared_ptr<Body> body;

    Function(char *, FormalParameters *, Type *);

    Function(char *, FormalParameters *, Type *, Body *);

    void print() const override;

    bool isForward() const override;
};