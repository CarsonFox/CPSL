#include "WhileStatement.hpp"

#include "FrontEnd/AST/Util.hpp"

WhileStatement::WhileStatement(Expression *e, StatementList *l) : pred(e) {
    stmts = l->toVector();
    delete l;
}

void WhileStatement::print() const {
    std::cout << "WHILE ";
    pred->print();
    std::cout << " DO\n";
    indentStatementList(stmts);
    std::cout << "\nEND";
}