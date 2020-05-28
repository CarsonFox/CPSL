#include <src/AST/Expressions/LiteralExpression.hpp>
#include "RepeatStatement.hpp"

#include "src/AST/Util.hpp"

#include "src/Labels.hpp"

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

void RepeatStatement::emit(SymbolTable &table, RegisterPool &pool) {
    const auto label = Labels::getRepeatLabel();

    std::cout << label << ":\n";

    for (auto &stmt: stmts) {
        stmt->emit(table, pool);
    }

    const auto reg = pred->emitToRegister(table, pool);

    std::cout << "bnez " << reg << ", " << label << " #test ";
    pred->print();
    std::cout << "\n\n";

    pool.freeRegister(reg);
}
