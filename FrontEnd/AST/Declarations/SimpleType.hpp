#pragma once

#include <string>

#include "Type.hpp"

struct SimpleType : Type {
    std::string id;

    SimpleType(char *);

    ~SimpleType() override = default;

    void accept(Visitor &) override;
};