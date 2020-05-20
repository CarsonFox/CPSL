#pragma once

#include "src/AST/ASTNode.hpp"

struct Subroutine : ASTNode {
    virtual bool isForward() const = 0;
};