#include "ReadStatement.hpp"

#include "src/AST/Util.hpp"
#include "src/AST/Types/Type.hpp"

ReadStatement::ReadStatement(LValueList *list) {
    lvals = list->toVector();
    delete list;

    if (lvals.empty()) {
        std::cerr << "Syntax error: Read requires arguments\n";
        std::exit(EXIT_FAILURE);
    }
}

void ReadStatement::print() const {
    std::cout << "READ(";
    printExprList(lvals);
    std::cout << ");";
}

void ReadStatement::emit(SymbolTable &table, RegisterPool &) {
    for (auto &lval: lvals) {
        const auto type = lval->getConcreteType(table)->getTypeEnum(table);

        if (type == Expression::integral || type == Expression::character) {
            std::cout << "li $v0, " << (type == Expression::integral ? "5" : "12")
                      << " #Read " << (type == Expression::integral ? "integer" : "character") << " syscall\n";
            std::cout << "syscall\n";
            std::cout << "sw $v0, " << lval->getLocation(table) << " #Store value read\n\n";
        } else {
            std::cout << "Cannot read into non-integral type ";
            lval->getConcreteType(table)->print();
            std::cout << std::endl;
            std::exit(14);
        }
    }
}
