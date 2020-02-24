#include "RepeatStatement.hpp"

#include "FrontEnd/AST/Util.hpp"

RepeatStatement::RepeatStatement(StatementList *l, Expression *e) : pred(e) {
    stmts = l->toVector();
    delete l;
}

void RepeatStatement::print() const {
    std::cout << "REPEAT";
    indentStatementList(stmts);
    std::cout << "UNTIL ";
    pred->print();
}
