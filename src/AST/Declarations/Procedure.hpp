#pragma once

#include <memory>
#include <string>

#include "Subroutine.hpp"
#include "FormalParameters.hpp"
#include "Body.hpp"

struct Procedure : Subroutine {
    Procedure(char *, FormalParameters *);

    Procedure(char *, FormalParameters *, Body *);

    ~Procedure() override = default;

    void print() const override;

    void fold_constants() override;
};