//
// Created by fox on 2/13/20.
//

#include "StatementList.hpp"

StatementList::StatementList(StatementList *l, Statement *r) : left(l), right(r) {

}

StatementList::~StatementList() {
    delete left;
    delete right;
}

std::vector<std::unique_ptr<Statement>> StatementList::toVector() {
    if (left) {
        auto v = left->toVector();

        if (right) {
            v.emplace_back(right);
            right = nullptr;
        }

        return v;
    }

    std::vector<std::unique_ptr<Statement>> v;

    if (right) {
        v.emplace_back(right);
        right = nullptr;
    }

    return v;
}
