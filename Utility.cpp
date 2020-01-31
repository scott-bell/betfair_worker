//
// Created by scott on 31/01/2020.
//

#include <sstream>
#include "Utility.h"

/*static*/ std::vector<std::string> Utility::split(std::string str, char delim) {
    std::vector<std::string> v{};
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        v.push_back(token);
    }
    return v;
}

/* static */ std::vector<std::string> Utility::split(std::string str,std::string delim){
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}