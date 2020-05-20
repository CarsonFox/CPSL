#include <src/AST/Expressions/LiteralExpression.hpp>
#include "RepeatStatement.hpp"

#include "src/AST/Util.hpp"

RepeatStatement::RepeatStatement(StatementList *l, Expression *e) : stmts(l->toVector()), pred(e) {
    delete l;
}

void RepeatStatement::print() const {
    std::cout << "REPEAT";
    indentStatementList(stmts);
    std::cout << "UNTIL ";
    pred->print();
}

void RepeatStatement::fold_constants() {
    const auto f_pred = pred->try_fold();
    if (f_pred)
        pred = std::shared_ptr<Expression>(new LiteralExpression(*f_pred));

    for (auto &stmt: stmts)
        stmt->fold_constants();
}
