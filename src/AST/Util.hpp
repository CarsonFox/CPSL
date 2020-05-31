#pragma once

#include <vector>
#include <memory>

#include "Expressions/Expression.hpp"
#include "Statements/Statement.hpp"

extern int indentLevel;

inline void newline() {
    std::cout << std::endl;
}

template<typename T>
void printExprList(const std::vector<std::shared_ptr<T>> &list) {
    if (!list.empty()) {
        for (auto it = list.begin(); it < list.end() - 1; it++) {
            (*it)->print();
            std::cout << ", ";
        }
        list.back()->print();
    }
}

void indentStatementList(const std::vector<std::shared_ptr<Statement>> &);

void indent();

void fillStackSize(const std::string &, int stackSize);