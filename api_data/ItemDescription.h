//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_ITEMDESCRIPTION_H
#define SXCLIENT_ITEMDESCRIPTION_H

#include <string>
#include <optional>

namespace API {
    struct ItemDescription {
        std::optional<std::string> eventTypeDesc;
        std::optional<std::string> eventDesc;
        std::optional<std::string> marketDesc;
        std::optional<std::string> marketType;
        std::optional<std::string> marketStartTime;
        std::optional<std::string> runnerDesc;
        std::optional<int> numberOfWinners;
        std::optional<double> eachWayDivisor;
    };
}

#endif //SXCLIENT_ITEMDESCRIPTION_H
