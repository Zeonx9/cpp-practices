//
// Created by musht on 30.11.2022.
//
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using str = std::string;
using sstream = std::stringstream;
using svector = std::vector<str>;

bool checkStrPalindrom(const str &s) {
    for (auto it1 = s.begin(), it2 = s.end() - 1; it1 < it2; ++it1, --it2)
        if (*it1 != *it2)
            return false;
    return true;
}

str sortWordsByLen(const str &s) {
    sstream ss(s);
    svector sv;
    str word;
    while (ss >> word)
        sv.push_back(word);

    // sorting by length
    std::sort(sv.begin(), sv.end(), [](str &a, str &b) { return a.size() < b.size(); });

    str out;
    for (auto &w : sv)
        out += w + " ";
    return out;
}

int main() {
    std::cout << checkStrPalindrom("hellolleh") << "\n";
    std::cout << sortWordsByLen("C++ is a very        performant language.");
}
