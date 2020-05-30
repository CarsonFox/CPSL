#pragma once

#include <memory>

#include "Subroutine.hpp"
#include "src/AST/Types/Type.hpp"

struct Function : Subroutine {
    std::shared_ptr<Type> type;

    Function(char *, FormalParameters *, Type *);

    Function(char *, FormalParameters *, Type *, Body *);

    ~Function() override = default;

    void print() const override;

    void fold_constants() override;
};