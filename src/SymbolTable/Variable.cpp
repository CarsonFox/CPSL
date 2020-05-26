#include "Variable.hpp"

#include <sstream>

std::string Variable::getLocation() const {
    std::stringstream ss;
    ss << offset << '(' << base << ')';
    return ss.str();
}

Variable::Variable(std::string id, std::shared_ptr<Type> type, std::string base, int offset)
        : id(std::move(id)),
          type(std::move(type)),
          base(std::move(base)),
          offset(offset) {
}

std::string Variable::getBase() const {
    return base;
}

int Variable::getOffset() const {
    return offset;
}

std::shared_ptr<Type> Variable::getConcreteType() const {
    return type;
}
