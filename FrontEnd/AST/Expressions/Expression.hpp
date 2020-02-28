#pragma once

#include "FrontEnd/AST/ASTNode.hpp"

struct Expression : ASTNode {
    virtual bool isConst() const = 0;
};