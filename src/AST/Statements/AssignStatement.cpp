#include "AssignStatement.hpp"

#include "src/AST/Expressions/LiteralExpression.hpp"
#include "src/AST/Expressions/IdentifierExpression.hpp"

AssignStatement::AssignStatement(LValue *l, Expression *e) : lvalue(l), expr(e) {}

void AssignStatement::print() const {
    lvalue->print();
    std::cout << " := ";
    expr->print();
    std::cout << ';';
}

void AssignStatement::fold_constants() {
    const auto folded = expr->try_fold();
    if (folded)
        expr = std::shared_ptr<Expression>(new LiteralExpression(*folded));
}

void AssignStatement::emit(SymbolTable &table, RegisterPool &pool) {
    if (std::dynamic_pointer_cast<IdentifierExpression>(lvalue)) {
        const auto reg = expr->emitToRegister(table, pool);

        std::cout << "sw " << reg << ", " << lvalue->getLocation(table) << " #";
        this->print();
        std::cout << "\n\n";

        pool.freeRegister(reg);
    } else {
        const auto exprReg = expr->emitToRegister(table, pool);
        const auto locReg = lvalue->emitLocationToRegister(table, pool);

        std::cout << "sw " << exprReg << ", (" << locReg << ") # ";
        this->print();
        std::cout << "\n\n";

        pool.freeRegister(exprReg);
        pool.freeRegister(locReg);
    }
}
