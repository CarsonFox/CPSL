#include "FunctionCallExpression.hpp"

void FunctionCallExpression::accept(Visitor &visitor) {
    visitor.visit(this);
}

FunctionCallExpression::FunctionCallExpression(char *s, ExpressionList *list) : id(s) {
    args = list->toVector();
    delete list;
    free(s); //Alloc'd using strdup
}
