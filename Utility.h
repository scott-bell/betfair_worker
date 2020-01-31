//
// Created by scott on 31/01/2020.
//

#ifndef BETFAIR_WORKER_UTILITY_H
#define BETFAIR_WORKER_UTILITY_H

#include <vector>
#include <string>

class Utility {
public:
    static std::vector<std::string> split(std::string str, char delim);
    static std::vector<std::string> split(std::string str, std::string delim);

};


#endif //BETFAIR_WORKER_UTILITY_H
