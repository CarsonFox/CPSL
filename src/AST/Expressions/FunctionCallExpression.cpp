#include "FunctionCallExpression.hpp"

#include "src/AST/Util.hpp"
#include "LiteralExpression.hpp"
#include "src/AST/Types/BuiltinType.hpp"

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

std::string FunctionCallExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    //Load arguments into registers
    for (auto &arg: args) {
        arg->emitToRegister(table, pool);
    }

    //Call function
    std::cout << "jal " << id << " #Call function\n";

    pool.clearRegisters();

    auto reg = pool.getRegister();
    std::cout << "move " << reg << ", $v0 #Load return value\n";
    return reg;
}

Expression::type FunctionCallExpression::getType(SymbolTable &table) {
    return table.lookupFunction(id)->getTypeEnum(table);
}
