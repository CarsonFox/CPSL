#include "WriteStatement.hpp"

#include <memory>

#include "src/AST/Expressions/LiteralExpression.hpp"
#include "src/AST/Util.hpp"

WriteStatement::WriteStatement(ExpressionList *list) {
    args = list->toVector();

    if (args.empty()) {
        std::cerr << "Syntax error: Write requires arguments\n";
        std::exit(EXIT_FAILURE);
    }

    delete list;
}

void WriteStatement::print() const {
    std::cout << "WRITE(";
    printExprList(args);
    std::cout << ");";
}

void WriteStatement::fold_constants() {
    for (auto &expr: args) {
        const auto folded = expr->try_fold();
        if (folded)
            expr = std::shared_ptr<Expression>(new LiteralExpression(*folded));
    }
}

void WriteStatement::emit(SymbolTable &table, RegisterPool &pool) {
    for (auto &expr: args) {
        //TODO detect type of integral expressions
//        if (std::dynamic_pointer_cast<LiteralExpression>(expr)) {
//            const auto reg = expr->emitToRegister(table, pool);
//            std::cout << "li $v0, "
//                      << (std::dynamic_pointer_cast<LiteralExpression>(expr)->isChar ? "11" : "1")
//                      << " #Print "
//                      << (std::dynamic_pointer_cast<LiteralExpression>(expr)->isChar ? "character" : "integer")
//                      << " syscall\n";
//            std::cout << "move $a0, " << reg << " #";
//            this->print();
//            std::cout << "\nsyscall\n\n";
//            pool.freeRegister(reg);
//        }

        const auto reg = expr->emitToRegister(table, pool);
        std::cout << "li $v0, 1 #Print integer syscall\n";
        std::cout << "move $a0, " << reg << " #";
        this->print();
        std::cout << "\nsyscall\n\n";
        pool.freeRegister(reg);
    }
}
