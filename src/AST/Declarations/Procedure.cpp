#include "Procedure.hpp"

#include <sstream>

#include "src/AST/Types/BuiltinType.hpp"

Procedure::Procedure(char *s, FormalParameters *fp) : id(s), param(fp) {
    free(s);
}

Procedure::Procedure(char *s, FormalParameters *fp, Body *b) : id(s), param(fp), body(b) {
    free(s);
}

bool Procedure::isForward() const {
    return !body;
}

void Procedure::print() const {
    std::cout << "PROCEDURE " << id << '(';
    param->print();
    if (this->isForward())
        std::cout << "); FORWARD;";
    else {
        std::cout << ");\n";
        body->print();
        std::cout << ';';
    }
}

void Procedure::fold_constants() {
    param->fold_constants();
    if (body)
        body->fold_constants();
}

void Procedure::saveParameters(SymbolTable &table, RegisterPool &pool) {
    for (const auto &[parType, ids, type]: param->members) {
        if (parType == REF_T) {
            std::cerr << "Reference parameters unsupported!\n";
            std::exit(15);
        } else {
            for (const auto var_id: ids) {
                table.addVariable(var_id, type);
                const auto reg = pool.getRegister();
                std::cout << "sw " << reg << ", " << table.lookupVariable(var_id).getLocation() << " #Store argument "
                          << var_id << std::endl;
            }
        }
    }
    pool.clearRegisters();
}

void Procedure::emit(SymbolTable &table, RegisterPool &pool) {
    std::cout << id << ":\n";

    /*
     * Redirect cout so code is emitted to populate the symbol table, without printing.
     * This way we know how much stack space to allocate.
     */
    std::stringstream ss_out;
    std::streambuf *old_cout = std::cout.rdbuf(ss_out.rdbuf());

    table.pushScope();
    saveParameters(table, pool);

    //Use " ", an invalid identifier, to store return address on stack
    table.addVariable(" ", std::shared_ptr<Type>(new BuiltinType(Expression::integral)));
    std::cout << "sw $ra, " << table.lookupVariable(" ").getLocation() << " #Save return address\n\n";

    body->emit(table, pool);

    //Reset cout
    std::cout.rdbuf(old_cout);

    //Create a stack frame, then emit code for body
    std::cout << "addiu $sp, $sp, -" << table.stackFrameSize() << " #Set up stack frame\n";
    std::cout << ss_out.str();
    std::cout << "lw $ra, " << table.lookupVariable(" ").getLocation() << " #Restore return address\n";
    std::cout << "jr $ra #Return from procedure " << id << "\n\n";

    table.popScope();
}
