#include "IfStatement.hpp"

#include "FrontEnd/AST/Util.hpp"

IfStatement::IfStatement(Expression *e, StatementList *l) : pred(e) {
    stmts = l->toVector();
    delete l;
}

void IfStatement::addElseIf(Expression *e, StatementList *l) {
    if (!elseStmts.empty()) {
        std::cerr << "Syntax error: ELSE must come after ELSE IF\n";
        std::exit(EXIT_FAILURE);
    }

    elseIfs.emplace_back(e, l->toVector());
    delete l;
}

void IfStatement::addElse(StatementList *l) {
    if (!elseStmts.empty()) {
        std::cerr << "Syntax error: IF Statement cannot have more than one ELSE\n";
        std::exit(EXIT_FAILURE);
    }

    elseStmts = l->toVector();
    delete l;
}

void IfStatement::print() const {
    std::cout << "IF ";
    pred->print();
    std::cout << " THEN\n";
    indentStatementList(stmts);

    for (const auto &[pred, stmts]: elseIfs) {
        std::cout << "ELSEIF ";
        pred->print();
        std::cout << " THEN\n";
        indentStatementList(stmts);
    }

    if (!elseStmts.empty()) {
        std::cout << "ELSE\n";
        indentStatementList(elseStmts);
    }

    std::cout << "END";
}