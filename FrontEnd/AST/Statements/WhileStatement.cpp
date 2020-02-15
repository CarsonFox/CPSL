#include "WhileStatement.hpp"

WhileStatement::WhileStatement(Expression *e, StatementList *l) : pred(e) {
    stmts = l->toVector();
    delete l;
}

void WhileStatement::accept(Visitor &visitor) {
    visitor.visit(this);
}
