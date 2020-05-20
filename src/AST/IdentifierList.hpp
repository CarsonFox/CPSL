#pragma once

#include <vector>
#include <string>

struct IdentifierList {
    std::vector<std::string> list;

    explicit IdentifierList(char *);

    IdentifierList(IdentifierList *, char *);

    ~IdentifierList() = default;
};