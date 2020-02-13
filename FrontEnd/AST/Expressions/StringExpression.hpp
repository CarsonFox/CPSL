#include <string>

#include "Expression.hpp"

struct StringExpression : Expression {
    std::string value;

    explicit StringExpression(char *);

    ~StringExpression() override = default;

    void accept(Visitor &) override;
};