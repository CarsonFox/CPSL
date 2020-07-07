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
    pool.saveRegisters(table);

    //Load arguments into registers
    for (auto &arg: args) {
        const auto reg = arg->emitToRegister(table, pool);
        std::cout << "move " << pool.getArgRegister() << ", " << reg << " #Hack: move to arg register\n";
        pool.freeRegister(reg);
    }

    //Call function
    std::cout << "jal " << id << " #Call function\n";

    pool.clearArgRegisters();
    pool.loadRegisters(table);

    auto reg = pool.getRegister();
    std::cout << "move " << reg << ", $v0 #Load return value\n";
    return reg;
}

Expression::type FunctionCallExpression::getType(SymbolTable &table) {
    return table.lookupFunction(id)->getTypeEnum(table);
}

void FunctionCallExpression::emitTailCall(SymbolTable &table, RegisterPool &pool) {
    //Tail call: the expression being returned is a function call.
    //Temporaries from previous stack frames were already saved, and this frame is junk.
    //Load arguments, delete stack frame, then jump to new function.

    //Load arguments into registers
    for (auto &arg: args) {
        const auto reg = arg->emitToRegister(table, pool);
        std::cout << "move " << pool.getArgRegister() << ", " << reg << " #Hack: move to arg register\n";
        pool.freeRegister(reg);
    }
    pool.clearArgRegisters();

    //Delete stack frame
    std::cout << "addiu $sp, $sp, * #Delete stack frame\n";

    //Call function
    std::cout << "j " << id << " #Tail call function\n";
}
