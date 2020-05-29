#include "ForStatement.hpp"

#include "src/AST/Util.hpp"

#include "src/AST/Types/BuiltinType.hpp"
#include "src/AST/Statements/AssignStatement.hpp"
#include "src/AST/Expressions/BinaryOperators/AddExpression.hpp"
#include "src/AST/Expressions/BinaryOperators/GreaterExpression.hpp"
#include "src/AST/Expressions/BinaryOperators/LessExpression.hpp"
#include "src/AST/Expressions/LiteralExpression.hpp"
#include "src/AST/Expressions/IdentifierExpression.hpp"
#include "src/Labels.hpp"

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

void ForStatement::emit(SymbolTable &table, RegisterPool &pool) {
    table.pushForScope();

    //Hack: treat the variable as an integer no matter what
    table.addVariable(id, std::shared_ptr<Type>(new BuiltinType()));

    //Emit code to assign the initial value
    AssignStatement(new IdentifierExpression(id), init).emit(table, pool);

    const auto[beginLabel, endLabel] = Labels::getForLabels();

    std::cout << beginLabel << ": #Begin for loop\n";

    //Bounds of for loops seem to be inclusive
    Expression *pred;
    if (type == ForType::UP_TO) {
        pred = new GreaterExpression(new IdentifierExpression(id), bound);
    } else {
        pred = new LessExpression(new IdentifierExpression(id), bound);
    }

    const auto reg = pred->emitToRegister(table, pool);
    std::cout << "bnez " << reg << ", " << endLabel << " #Test condition ";
    pred->print();
    std::cout << "\n\n";

    delete pred;

    for (auto &stmt: statements) {
        stmt->emit(table, pool);
    }

    Expression *difference;
    if (type == ForType::UP_TO) {
        difference = new LiteralExpression(1);
    } else {
        difference = new LiteralExpression(-1);
    }

    //id = id + difference
    AssignStatement(new IdentifierExpression(id), new AddExpression(new IdentifierExpression(id), difference)).emit(
            table, pool);

    std::cout << "j " << beginLabel << " #Jump to next iteration of the for loop\n";
    std::cout << endLabel << ": #End for loop\n\n";

    table.popScope();
}
