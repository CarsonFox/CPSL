#pragma once

#include <optional>

#include "FrontEnd/AST/ASTNode.hpp"

struct Expression : ASTNode {
    virtual bool isConst() const = 0;

    virtual std::optional<int> try_fold() const {
        return std::nullopt;
    }
};