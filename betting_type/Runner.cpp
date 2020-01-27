//
// Created by scott on 24/01/2020.
//

#include "Runner.h"

Runner::Runner(Json::Value json) {
    selectionId = json["selectionId"].asInt64();
    handicap = json["handicap"].asDouble();
    status = json["status"].asString();
    adjustmentFactor = json["adjustmentFactor"].asDouble();
    if (json.isMember("lastPriceTraded"))
        lastPriceTraded = json["lastPriceTraded"].asDouble();
    if (json.isMember("totalMatched"))
        totalMatched = json["totalMatched"].asDouble();
    if (json.isMember("removalDate"))
        removalDate = json["removalDate"].asString();
    if (json.isMember("sp"))
        sp = StartingPrices(json["sp"]);
    if (json.isMember("sp"))
        ex = ExchangePrices(json["ex"]);
    if (json.isMember("orders")) {
        const Json::Value result = json["orders"];
        std::vector<Order> v;
        for (const auto & index : result)
        {
            v.emplace_back(Order(index));
        }
        orders = v;
    }
    if (json.isMember("matches")) {
        const Json::Value result = json["matches"];
        std::vector<Match> v;
        for (const auto & index : result)
        {
            v.emplace_back(Match(index));
        }
        matches = v;
    }
    // TODO: matchesByStrategy

}
