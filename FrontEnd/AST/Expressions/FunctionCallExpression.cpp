#include "FunctionCallExpression.hpp"
#include "FrontEnd/AST/Util.hpp"

FunctionCallExpression::FunctionCallExpression(char *s, ExpressionList *list) : id(s) {
    args = list->toVector();
    delete list;
    free(s); //Alloc'd using strdup
}

void FunctionCallExpression::print() const {
    std::cout << id << '(';
    printExprList(args);
    std::cout << ')';
}

//No constexpr support :( unless...
bool FunctionCallExpression::isConst() const {
    return false;
}
