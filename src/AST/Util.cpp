#include "Util.hpp"

#include "Statements/EmptyStatement.hpp"

int indentLevel = 0;

void indentStatementList(const std::vector<std::shared_ptr<Statement>> &list) {
    indentLevel++;
    for (auto it = list.begin(); it < list.end() - 1; it++) {
        indent();
        (*it)->print();
        newline();
    }
    if (!list.empty() && !dynamic_cast<const EmptyStatement *>(list.back().get())) {
        indent();
        list.back()->print();
    }
    indentLevel--;
}

void indent() {
    for (int i = 0; i < indentLevel; i++)
        std::cout << '\t';
}