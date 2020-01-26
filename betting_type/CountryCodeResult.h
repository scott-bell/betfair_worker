//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_COUNTRYCODERESULT_H
#define BETFAIR_WORKER_COUNTRYCODERESULT_H


#include <string>
#include <optional>

struct CountryCodeResult {
    std::optional<std::string> countryCode;
    std::optional<int> marketCount;
};


#endif //BETFAIR_WORKER_COUNTRYCODERESULT_H
