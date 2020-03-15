#include <FrontEnd/AST/Expressions/LiteralExpression.hpp>
#include "ProcedureCallStatement.hpp"

#include "FrontEnd/AST/Util.hpp"

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
