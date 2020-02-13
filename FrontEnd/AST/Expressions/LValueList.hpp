#pragma once

#include <vector>
#include <memory>

#include "LValue.hpp"

/*
 * Meta-class that helps parse a list of Expressions left-recursive style.
 * Yields a vector once the list's done parsing.
 */
class LValueList {
private:
    LValueList *left;
    LValue *right;

public:
    LValueList(LValueList *, LValue *);

    ~LValueList();

    std::vector<std::unique_ptr<LValue>> toVector();
};