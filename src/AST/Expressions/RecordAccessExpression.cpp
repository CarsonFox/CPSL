#include "RecordAccessExpression.hpp"

#include "src/AST/Types/RecordType.hpp"

RecordAccessExpression::RecordAccessExpression(LValue *l, char *r) : left(l), right(r) {
    free(r);
}

void RecordAccessExpression::print() const {
    left->print();
    std::cout << '.' << right;
}

bool RecordAccessExpression::isConst() const {
    return false;
}

std::string RecordAccessExpression::emitLocationToRegister(SymbolTable &table, RegisterPool &pool) {
    const auto locReg = left->emitLocationToRegister(table, pool);

    const auto record = std::dynamic_pointer_cast<RecordType>(left->getConcreteType(table));

    if (!record) {
        left->print();
        std::cout << " is not a Record\n";
        std::exit(11);
    }

    //compute offset for this record member
    int offset = 0;
    for (const auto &[ids, type]: record->members) {
        for (const auto &id : ids) {
            if (id == this->right) {
                std::cout << "addi " << locReg << ", " << locReg << ", " << offset
                          << " #Compute location of member " << id << std::endl;
                return locReg;
            } else {
                offset += type->getSize(table);
            }
        }
    }

    std::cout << right << " does not name a member of ";
    record->print();
    std::cout << std::endl;
    std::exit(12);
}

std::string RecordAccessExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    auto reg = this->emitLocationToRegister(table, pool);

    std::cout << "lw " << reg << ", (" << reg << ") #";
    this->print();
    std::cout << std::endl;

    return reg;
}

std::shared_ptr<Type> RecordAccessExpression::getConcreteType(SymbolTable &table) {
    const auto record = std::dynamic_pointer_cast<RecordType>(left->getConcreteType(table));

    if (!record) {
        std::cout << "Cannot access non-record type ";
        left->print();
        std::cout << std::endl;
        std::exit(10);
    }

    for (const auto &[ids, type]: record->members) {
        for (const auto &id: ids) {
            if (id == this->right) {
                return type;
            }
        }
    }

    std::cout << this->right << " does not name a member of record ";
    this->left->print();
    std::cout << std::endl;
    std::exit(12);
}
