#pragma once

#include <memory>

struct Type;

class SymbolTableType {
public:
    SymbolTableType() = default;

    SymbolTableType(std::shared_ptr<Type> type);
};