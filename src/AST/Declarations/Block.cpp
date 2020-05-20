#include "Block.hpp"

#include "src/AST/Util.hpp"

Block::Block(StatementList *l) {
    stmts = l->toVector();
    delete l;
}

void Block::print() const {
    std::cout << "BEGIN\n";
    indentStatementList(stmts);
    std::cout << "END";
}

void Block::fold_constants() {
    for (auto &stmt: stmts)
        stmt->fold_constants();
}
