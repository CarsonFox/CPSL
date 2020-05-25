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
        switch (expr->getType(table)) {
            case Expression::integral:
                printIntegral(table, pool, expr);
                continue;

            case Expression::character:
                printCharacter(table, pool, expr);
                continue;

            case Expression::string:
                printString(table, pool, expr);
                continue;

            case Expression::userDefined:
                std::cout << "Cannot print user-defined type: ";
                expr->print();
                std::cout << std::endl;
                std::exit(6);
        }
    }
}

void WriteStatement::printIntegral(SymbolTable &table, RegisterPool &pool, const std::shared_ptr<Expression> &expr) {
    const auto reg = expr->emitToRegister(table, pool);
    std::cout << "li $v0, 1 #Print integer syscall\n";
    std::cout << "move $a0, " << reg << " #";
    this->print();
    std::cout << "\nsyscall\n\n";
    pool.freeRegister(reg);
}

void WriteStatement::printCharacter(SymbolTable &table, RegisterPool &pool, const std::shared_ptr<Expression> &expr) {
    const auto reg = expr->emitToRegister(table, pool);
    std::cout << "li $v0, 11 #Print character syscall\n";
    std::cout << "move $a0, " << reg << " #";
    this->print();
    std::cout << "\nsyscall\n\n";
    pool.freeRegister(reg);
}

void WriteStatement::printString(SymbolTable &table, RegisterPool &pool, const std::shared_ptr<Expression> &expr) {
    const auto reg = expr->emitToRegister(table, pool);
    std::cout << "li $v0, 4 #Print string syscall\n";
    std::cout << "move $a0, " << reg << " #";
    this->print();
    std::cout << "\nsyscall\n\n";
    pool.freeRegister(reg);
}
