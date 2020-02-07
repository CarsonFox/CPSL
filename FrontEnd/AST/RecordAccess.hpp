#pragma once

#include "AST.hpp"

struct RecordAccess : ASTNode {
    std::string record, member;

    RecordAccess(char *, char *);

    void prettyPrint() const override;
};