//
// Created by scott on 23/01/2020.
//

#ifndef SXCLIENT_MARKETLINERANGEINFO_H
#define SXCLIENT_MARKETLINERANGEINFO_H

#include <string>
#include <jsoncpp/json/value.h>

namespace API {
    struct MarketLineRangeInfo {

        double maxUnitValue;
        double minUnitValue;
        double interval;
        std::string marketUnit;

        explicit MarketLineRangeInfo(Json::Value json);

    };
}

#endif //SXCLIENT_MARKETLINERANGEINFO_H
