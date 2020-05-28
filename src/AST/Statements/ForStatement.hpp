#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Statement.hpp"
#include "src/AST/Expressions/Expression.hpp"
#include "StatementList.hpp"

enum ForType {
    UP_TO,
    DOWN_TO,
};

struct ForStatement : Statement {
    std::string id;
    std::shared_ptr<Expression> init, bound;
    std::vector<std::shared_ptr<Statement>> statements;
    ForType type;

    ForStatement(char *, Expression *, Expression *, StatementList *, ForType);

    ~ForStatement() override = default;

    void print() const override;

    void fold_constants() override;

    void emit(SymbolTable &table, RegisterPool &pool) override;
};