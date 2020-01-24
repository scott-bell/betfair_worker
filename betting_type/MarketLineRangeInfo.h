//
// Created by scott on 23/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETLINERANGEINFO_H
#define BETFAIR_WORKER_MARKETLINERANGEINFO_H

#include <string>
#include <jsoncpp/json/value.h>

struct MarketLineRangeInfo {

    double maxUnitValue;
    double minUnitValue;
    double interval;
    std::string marketUnit;

    explicit MarketLineRangeInfo(Json::Value json);

};


#endif //BETFAIR_WORKER_MARKETLINERANGEINFO_H
