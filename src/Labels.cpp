#include "Labels.hpp"

#include <sstream>
#include <iostream>

int Labels::x = 0;
std::vector<StringPair> Labels::strings = {};

void Labels::emitStrings() {
    for (const auto &[label, str] : strings) {
        std::cout << label << ": .asciiz " << str << std::endl;
    }
}

std::string Labels::getStringLabel(const std::string &str) {
    std::stringstream ss;
    ss << "string_" << x++;

    //Need to keep the label and string content to emit at the end
    strings.emplace_back(ss.str(), str);

    return ss.str();
}
