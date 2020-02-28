#include "Block.hpp"

#include "FrontEnd/AST/Util.hpp"

Block::Block(StatementList *l) {
    stmts = l->toVector();
    delete l;
}

void Block::print() const {
    std::cout << "BEGIN\n";
    indentStatementList(stmts);
    std::cout << "END";
}