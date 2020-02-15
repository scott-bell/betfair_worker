//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_COUNTRYCODERESULT_H
#define SXCLIENT_COUNTRYCODERESULT_H


#include <string>
#include <optional>

namespace API {
    struct CountryCodeResult {
        std::optional<std::string> countryCode;
        std::optional<int> marketCount;
    };
}

#endif //SXCLIENT_COUNTRYCODERESULT_H
