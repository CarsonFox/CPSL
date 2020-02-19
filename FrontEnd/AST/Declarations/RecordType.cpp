#include "RecordType.hpp"

RecordType::RecordType(IdentifierList *l, Type *t) {
    members.emplace_back(std::move(l->list), t);
    delete l;
}

RecordType::RecordType(RecordType *r, IdentifierList *l, Type *t) {
    members = std::move(r->members);
    members.emplace_back(std::move(l->list), t);
    delete r;
    delete l;
}

void RecordType::accept(Visitor &visitor) {
    visitor.visit(this);
}
