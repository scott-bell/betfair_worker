//
// Created by scott on 23/01/2020.
//

#include "MarketDescription.h"

namespace API {
    MarketDescription::MarketDescription(const Json::Value &json) {

        persistenceEnabled = json["persistenceEnabled"].asBool();
        bspMarket = json["bspMarket"].asBool();
        marketTime = json["marketTime"].asString();
        suspendTime = json["suspendTime"].asString();
        if (json.isMember("settleTime"))
            settleTime = json["settleTime"].asString();
        bettingType = json["bettingType"].asString();
        turnInPlayEnabled = json["turnInPlayEnabled"].asBool();
        marketType = json["marketType"].asString();
        regulator = json["regulator"].asString();
        marketBaseRate = json["marketBaseRate"].asDouble();
        discountAllowed = json["discountAllowed"].asBool();

        if (json.isMember("wallet"))
            wallet = json["wallet"].asString();
        if (json.isMember("rules"))
            rules = json["rules"].asString();
        if (json.isMember("rulesHasDate"))
            rulesHasDate = json["rulesHasDate"].asBool();
        if (json.isMember("eachWayDivisor"))
            eachWayDivisor = json["eachWayDivisor"].asDouble();
        if (json.isMember("clarifications"))
            clarifications = json["clarifications"].asString();
        if (json.isMember("lineRangeInfo"))
            lineRangeInfo = MarketLineRangeInfo(json["lineRangeInfo"]);
        if (json.isMember("raceType"))
            raceType = json["raceType"].asString();
        if (json.isMember("priceLadderDescription"))
            priceLadderDescription = PriceLadderDescription(json["priceLadderDescription"]);


    }
}