#include "LiteralExpression.hpp"

LiteralExpression::LiteralExpression(int x) : value(x) {
}

LiteralExpression::LiteralExpression(char c) : value(c) {
}

std::string escape(char c) {
    switch (c) {
        case '\n':
            return "\\n";
        case '\t':
            return "\\t";
        case '\b':
            return "\\b";
        case '\r':
            return "\\r";
        case '\f':
            return "\\f";
        default:
            return {c};
    }
}

void LiteralExpression::print() const {
    if (std::holds_alternative<int>(value)) {
        std::cout << std::get<int>(value);
    } else {
        std::cout << escape(std::get<char>(value));
    }
}

bool LiteralExpression::isConst() const {
    return true;
}
