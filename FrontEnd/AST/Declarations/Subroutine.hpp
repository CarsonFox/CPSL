#pragma once

#include "FrontEnd/AST/ASTNode.hpp"

struct Subroutine : ASTNode {
    virtual bool isForward() const = 0;
};