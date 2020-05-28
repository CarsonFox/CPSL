#pragma once

#include <string>
#include <vector>
#include <tuple>

using StringPair = std::pair<std::string, std::string>;

class Labels {
    //Global variable to keep identifiers unique
    static int x;
    //Might as well keep the strings here too
    static std::vector<StringPair> strings;
public:
    static void emitStrings();

    static std::string getStringLabel(const std::string &);

    static StringPair getWhileLabels();

    static std::string getRepeatLabel();

    static std::string getIfLabel();
};