#include "LValueList.hpp"

LValueList::LValueList(LValueList *l, LValue *r) : left(l), right(r) {

}

LValueList::~LValueList() {
    delete left;
    delete right;
}

std::vector<std::unique_ptr<LValue>> LValueList::toVector() {
    if (left) {
        auto v = left->toVector();

        if (right) {
            v.emplace_back(right);
            right = nullptr;
        }

        return v;
    }

    std::vector<std::unique_ptr<LValue>> v;

    if (right) {
        v.emplace_back(right);
        right = nullptr;
    }

    return v;
}
