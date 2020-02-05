#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

struct Program;

struct ASTNode {
    static Program *main;

    ASTNode() = default;

    virtual void prettyPrint() const = 0;

    virtual ~ASTNode() = default;
};

template<typename T>
std::vector<T> castNodeList(std::vector<ASTNode *> *v) {
    if (v) {
        std::vector<T> out;

        //ASTNode* ==> some subtype conversion. Requires that subtype has constructor from pointer.
        //This will reverse the order, which was already reversed in the parser. (right recursion)
        std::transform(v->begin(), v->end(), std::back_inserter(out),
                       [](ASTNode *node) { return T(node); });

        //Clean up
        for (ASTNode *p : *v) {
            delete ((T *) p);
        }
        delete v;

        return out;
    } else {
        std::cerr << "Tried to cast null vector pointer to subtype."
                  << "Should be a pointer to an empty vector if there aren't any.\n";
        exit(EXIT_FAILURE);
    }
}
