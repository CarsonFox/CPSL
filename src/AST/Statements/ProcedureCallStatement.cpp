#include <src/AST/Expressions/LiteralExpression.hpp>
#include "ProcedureCallStatement.hpp"

#include "src/AST/Util.hpp"

#include "src/AST/Types/BuiltinType.hpp"

ProcedureCallStatement::ProcedureCallStatement(char *s, ExpressionList *list) : id(s) {
    args = list->toVector();

    free(s); //Alloc'd with strdup
    delete list; //Alloc'd with new
}

void ProcedureCallStatement::print() const {
    std::cout << id << '(';
    printExprList(args);
    std::cout << ");";
}

void ProcedureCallStatement::fold_constants() {
    for (auto &arg: args) {
        const auto folded = arg->try_fold();
        if (folded)
            arg = std::shared_ptr<Expression>(new LiteralExpression(*folded));
    }
}

void ProcedureCallStatement::emit(SymbolTable &table, RegisterPool &pool) {
    /*
     * This is horrible. Basically assume no register leaks, and load each argument into registers in order.
     * Then save them in that order after calling.
     */

    pool.saveRegisters(table);

    //Load arguments into registers
    for (auto &arg: args) {
        const auto reg = arg->emitToRegister(table, pool);
        std::cout << "move " << pool.getArgRegister() << ", " << reg << " #Hack: move to arg register\n";
        pool.freeRegister(reg);
    }

    //Call subroutine
    std::cout << "jal " << id << " #Call procedure\n";

    pool.clearArgRegisters();
    pool.loadRegisters(table);
}
