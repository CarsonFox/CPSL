#include "ForStatement.hpp"

#include "FrontEnd/AST/Util.hpp"

ForStatement::ForStatement(char *s, Expression *i, Expression *b, StatementList *stmts, ForType t)
        : id(s), init(i), bound(b), type(t) {
    free(s);
    statements = stmts->toVector();
    delete stmts;
}

void ForStatement::print() const {
    std::cout << "FOR " << id << " := ";
    init->print();
    if (type == ForType::UP_TO)
        std::cout << " TO ";
    else
        std::cout << " DOWNTO ";
    bound->print();
    std::cout << " DO\n";
    indentStatementList(statements);
    std::cout << "END";
}