#pragma once

#include <memory>
#include <vector>

#include "Statement.hpp"

struct StatementList {
    StatementList *left;
    Statement *right;

    StatementList(StatementList *, Statement *);

    ~StatementList();

    std::vector<std::shared_ptr<Statement>> toVector();
};