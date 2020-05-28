#include <src/AST/Expressions/LiteralExpression.hpp>
#include "WhileStatement.hpp"

#include "src/AST/Util.hpp"
#include "src/Labels.hpp"

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

void WhileStatement::emit(SymbolTable &table, RegisterPool &pool) {
    const auto[begin, end] = Labels::getWhileLabels();

    std::cout << begin << ":\n";

    const auto reg = pred->emitToRegister(table, pool);
    std::cout << "beqz " << reg << ", " << end << " #test ";
    pred->print();
    std::cout << "\n\n";

    pool.freeRegister(reg);

    for (auto &stmt: stmts) {
        stmt->emit(table, pool);
    }

    std::cout << "j " << begin << " #Next while iteration\n";
    std::cout << end << ":\n\n";
}
