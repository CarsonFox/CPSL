#include <src/AST/Expressions/LiteralExpression.hpp>
#include "ForStatement.hpp"

#include "src/AST/Util.hpp"

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

void ForStatement::fold_constants() {
    const auto i = init->try_fold();
    if (i)
        init = std::shared_ptr<Expression>(new LiteralExpression(*i));

    const auto b = bound->try_fold();
    if (b)
        bound = std::shared_ptr<Expression>(new LiteralExpression(*b));

    for (auto &stmt: statements)
        stmt->fold_constants();
}
