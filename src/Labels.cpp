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

StringPair Labels::getWhileLabels() {
    std::stringstream ssBegin, ssEnd;

    ssBegin << "while_begin_" << x;
    ssEnd << "while_end_" << x++;

    return {ssBegin.str(), ssEnd.str()};
}

std::string Labels::getRepeatLabel() {
    std::stringstream ss;
    ss << "repeat_" << x++;
    return ss.str();
}

std::string Labels::getIfLabel() {
    std::stringstream ss;
    ss << "if_" << x++;
    return ss.str();
}
