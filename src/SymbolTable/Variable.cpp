#include "Variable.hpp"

#include <sstream>

std::string Variable::getLocation() const {
    std::stringstream ss;
    ss << offset << '(' << base << ')';
    return ss.str();
}
