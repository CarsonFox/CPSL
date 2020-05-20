#include "ExpressionList.hpp"

ExpressionList::ExpressionList(ExpressionList *l, Expression *r) : left(l), right(r) {
}

ExpressionList::~ExpressionList() {
    delete left;
    delete right;
}

std::vector<std::shared_ptr<Expression>> ExpressionList::toVector() {
    if (left) {
        auto v = left->toVector();

        if (right) {
            v.emplace_back(right);
            right = nullptr;
        }

        return v;
    }

    std::vector<std::shared_ptr<Expression>> v;

    if (right) {
        v.emplace_back(right);
        right = nullptr;
    }

    return v;
}
