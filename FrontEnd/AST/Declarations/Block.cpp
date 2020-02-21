#include "Block.hpp"

Block::Block(StatementList *l) {
    stmts = l->toVector();
    delete l;
}

void Block::accept(Visitor &visitor) {
    visitor.visit(this);
}
