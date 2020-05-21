#include "Variable.hpp"

#include <sstream>

std::string Variable::getLocation() const {
    std::stringstream ss;
    ss << offset << '(' << base << ')';
    return ss.str();
}

Variable::Variable(std::string id, std::shared_ptr<Type> type, std::string base) : id(std::move(id)),
                                                                                   type(std::move(type)),
                                                                                   base(std::move(base)) {
    offset = 0;
}
