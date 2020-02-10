#pragma once

#include "Visitor.hpp"

struct ASTNode {
    virtual ~ASTNode() = default;

    virtual void accept(Visitor &) = 0;
};