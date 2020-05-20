#pragma once

#include <optional>

#include "src/AST/ASTNode.hpp"

struct Expression : ASTNode {
    virtual bool isConst() const = 0;

    virtual std::optional<int> try_fold() {
        return {};
    }
};