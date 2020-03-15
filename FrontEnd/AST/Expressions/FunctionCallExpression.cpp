#include "FunctionCallExpression.hpp"
#include "FrontEnd/AST/Util.hpp"
#include "LiteralExpression.hpp"

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

std::optional<int> FunctionCallExpression::try_fold() {
    for (auto &arg: args) {
        const auto f_arg = arg->try_fold();
        if (f_arg)
            arg = std::shared_ptr<Expression>(new LiteralExpression(*f_arg));
    }
    return {};
}
