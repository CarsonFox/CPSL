#pragma once

#include <string>

#include "Type.hpp"

struct SimpleType : Type {
    std::string id;

    explicit SimpleType(char *);

    ~SimpleType() override = default;

    void print() const override;
};