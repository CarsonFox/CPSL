#include <src/AST/Expressions/LiteralExpression.hpp>
#include "IfStatement.hpp"

#include "src/AST/Util.hpp"

#include "src/Labels.hpp"

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

void IfStatement::fold_constants() {
    const auto f_pred = pred->try_fold();
    if (f_pred)
        pred = std::shared_ptr<Expression>(new LiteralExpression(*f_pred));

    for (auto &stmt: stmts)
        stmt->fold_constants();

    for (auto &[pred, stmts]: elseIfs) {
        const auto f = pred->try_fold();
        if (f)
            pred = std::shared_ptr<Expression>(new LiteralExpression(*f));

        for (auto &stmt: stmts)
            stmt->fold_constants();
    }

    for (auto &stmt: elseStmts)
        stmt->fold_constants();
}

void IfStatement::emit(SymbolTable &table, RegisterPool &pool) {
    const auto endLabel = Labels::getIfLabel();

    emitIf(table, pool, pred, stmts, endLabel);

    for (auto &[pred, stmts]: elseIfs) {
        emitIf(table, pool, pred, stmts, endLabel);
    }

    if (!elseStmts.empty()) {
        std::cout << "#Else:\n";
        for (auto &stmt: elseStmts) {
            stmt->emit(table, pool);
        }
    }

    std::cout << endLabel << ":\n\n";
}

void IfStatement::emitIf(SymbolTable &table, RegisterPool &pool, std::shared_ptr<Expression> &pred,
                         std::vector<std::shared_ptr<Statement>> &stmts, const std::string &endLabel) {
    const auto ifLabel = Labels::getIfLabel();
    const auto reg = pred->emitToRegister(table, pool);

    std::cout << "beqz " << reg << ", " << ifLabel << " #Test condition ";
    pred->print();
    std::cout << std::endl;

    pool.freeRegister(reg);

    for (auto &stmt: stmts) {
        stmt->emit(table, pool);
    }

    std::cout << "j " << endLabel << " #Jump to end of if statement\n\n";

    std::cout << ifLabel << ":\n\n";
}
