#include "LiteralExpression.hpp"

LiteralExpression::LiteralExpression(int x) : isChar(false), value(x) {
}

LiteralExpression::LiteralExpression(char c) : isChar(true), value(c) {
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
    if (isChar) {
        std::cout << escape(static_cast<char>(value));
    } else {
        std::cout << value;
    }
}

bool LiteralExpression::isConst() const {
    return true;
}

std::optional<int> LiteralExpression::try_fold() const {
    return {value};
}
