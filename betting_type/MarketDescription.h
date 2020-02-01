//
// Created by scott on 23/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETDESCRIPTION_H
#define BETFAIR_WORKER_MARKETDESCRIPTION_H

#include <string>
#include <optional>
#include <jsoncpp/json/value.h>
#include "MarketLineRangeInfo.h"
#include "PriceLadderDescription.h"


struct MarketDescription {
    bool persistenceEnabled;
    bool bspMarket;
    std::string marketTime;
    std::string suspendTime;
    std::optional<std::string> settleTime;
    std::string bettingType;        // MarketBettingType enum
    bool turnInPlayEnabled;
    std::string marketType;
    std::string regulator;
    double marketBaseRate;
    bool discountAllowed;
    std::optional<std::string> wallet;
    std::optional<std::string> rules;
    std::optional<bool> rulesHasDate;
    std::optional<double> eachWayDivisor;
    std::optional<std::string> clarifications;
    std::optional<MarketLineRangeInfo> lineRangeInfo;
    std::optional<std::string> raceType;
    std::optional<PriceLadderDescription> priceLadderDescription;

    explicit MarketDescription(const Json::Value& json);
};


#endif //BETFAIR_WORKER_MARKETDESCRIPTION_H
