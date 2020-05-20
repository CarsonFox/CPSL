#include "IdentifierList.hpp"

IdentifierList::IdentifierList(char *s) {
    list.emplace_back(s);
    free(s);
}

IdentifierList::IdentifierList(IdentifierList *i, char *s) {
    list = std::move(i->list);
    list.emplace_back(s);

    delete i;
    free(s);
}
