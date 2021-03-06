#include "RecordType.hpp"

#include "src/AST/Util.hpp"

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

void RecordType::print() const {
    std::cout << "RECORD\n";
    indentLevel++;
    for (const auto &[ids, type]: members) {
        indent();
        for (auto it = ids.begin(); it < ids.end() - 1; it++)
            std::cout << *it << ", ";
        std::cout << ids.back() << ": ";
        type->print();
        std::cout << ";\n";
    }
    indentLevel--;
    std::cout << "END";
}

void RecordType::fold_constants() {
    for (auto &[ids, type]: members)
        type->fold_constants();
}

int RecordType::getSize(SymbolTable &table) {
    int sum = 0;
    for (const auto &[ids, type]: members) {
        sum += static_cast<int>(ids.size()) * type->getSize(table);
    }
    return sum;
}

Expression::type RecordType::getTypeEnum(SymbolTable &) const {
    return Expression::userDefined;
}
