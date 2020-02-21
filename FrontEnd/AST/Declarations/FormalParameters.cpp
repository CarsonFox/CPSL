#include <iostream>

#include "FormalParameters.hpp"

FormalParameters::FormalParameters(ParType parType, IdentifierList *l, Type *t) {
    members.emplace_back(parType, std::move(l->list), t);
    delete l;
}

FormalParameters::FormalParameters(FormalParameters *left, FormalParameters *right) {
    if (!left) {
        std::cerr << "Syntax error: Empty formal parameter\n";
        std::exit(EXIT_FAILURE);
    }
    if (right->members.size() != 1) {
        std::cerr << "Expected right parameter list to have size 1\n";
        std::exit(EXIT_FAILURE);
    }

    members = std::move(left->members);
    auto &[pt, l, t] = right->members[0];
    members.emplace_back(pt, std::move(l), std::move(t));

    delete left;
    delete right;
}

void FormalParameters::accept(Visitor &visitor) {
    visitor.visit(this);
}
