#include <src/AST/Expressions/LiteralExpression.hpp>
#include "ReturnStatement.hpp"

ReturnStatement::ReturnStatement(Expression *e) : expr(e) {
}

void ReturnStatement::print() const {
    std::cout << "RETURN ";
    expr->print();
    std::cout << ';';
}

void ReturnStatement::fold_constants() {
    const auto folded = expr->try_fold();
    if (folded)
        expr = std::shared_ptr<Expression>(new LiteralExpression(*folded));
}

void ReturnStatement::emit(SymbolTable &table, RegisterPool &pool) {
    if (expr) {
        const auto reg = expr->emitToRegister(table, pool);

        std::cout << "move $v0, " << reg << " #";
        print();
        std::cout << std::endl;

        pool.freeRegister(reg);
    }

    std::cout << "lw $ra, " << table.lookupVariable("").getLocation() << " #Restore return address\n";
    std::cout << "addiu $sp, $sp, " << table.stackFrameSize() << " #Delete stack frame\n";
    std::cout << "jr $ra #Return to caller\n";
}
