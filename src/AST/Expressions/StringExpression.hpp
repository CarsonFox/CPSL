#include <string>

#include "Expression.hpp"

struct StringExpression : Expression {
    std::string value;

    explicit StringExpression(char *);

    ~StringExpression() override = default;

    void print() const override;

    bool isConst() const override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;

    type getType(SymbolTable &table) override;
};