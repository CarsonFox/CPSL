#include <FrontEnd/AST/Expressions/LiteralExpression.hpp>
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

void WhileStatement::fold_constants() {
    const auto f_pred = pred->try_fold();
    if (f_pred)
        pred = std::shared_ptr<Expression>(new LiteralExpression(*f_pred));

    for (auto &stmt: stmts)
        stmt->fold_constants();
}
