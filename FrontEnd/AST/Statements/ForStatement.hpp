#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Statement.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"
#include "StatementList.hpp"

enum ForType {
    UP_TO,
    DOWN_TO,
};

struct ForStatement : Statement {
    std::string id;
    std::unique_ptr<Expression> init, bound;
    std::vector<std::unique_ptr<Statement>> statements;
    ForType type;

    ForStatement(char *, Expression *, Expression *, StatementList *, ForType);

    ~ForStatement() override = default;

    void accept(Visitor &) override;
};