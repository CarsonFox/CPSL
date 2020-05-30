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

    //Empty string is an invalid identifier, so it can be used for the stack pointer
    table.addVariable("", std::shared_ptr<Type>(new BuiltinType(Expression::integral)));
    std::cout << "sw $sp, " << table.lookupVariable("").getLocation() << " #Save stack pointer\n";

    //Load arguments into registers
    for (auto &arg: args) {
        arg->emitToRegister(table, pool);
    }

    //Call subroutine
    std::cout << "jal " << id << " #Call procedure\n";

    //Restore stack pointer
    std::cout << "lw $sp, " << table.lookupVariable("").getLocation() << " #Restore stack pointer\n\n";
}
