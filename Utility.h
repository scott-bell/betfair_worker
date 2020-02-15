//
// Created by scott on 31/01/2020.
//

#ifndef SXCLIENT_UTILITY_H
#define SXCLIENT_UTILITY_H

#include <vector>
#include <string>

class Utility {
public:
    static std::vector<std::string> split(std::string str, char delim);
    static std::vector<std::string> split(std::string str, std::string delim);

};


#endif //SXCLIENT_UTILITY_H
