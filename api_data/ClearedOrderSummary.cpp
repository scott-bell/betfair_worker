//
// Created by scott on 24/01/2020.
//

#include "ClearedOrderSummary.h"

API::ClearedOrderSummary::ClearedOrderSummary(Json::Value json) {
    if (json.isMember("side"))
        side = json["side"].asString();
    if (json.isMember("orderType"))
        orderType = json["orderType"].asString();
    if (json.isMember("persistenceType"))
        persistenceType = json["persistenceType"].asString();
    if (json.isMember("customerStrategyRef"))
        customerStrategyRef = json["customerStrategyRef"].asString();
    if (json.isMember("customerStrategyRef"))
        customerStrategyRef = json["customerStrategyRef"].asString();
    if (json.isMember("betOutcome"))
        betOutcome = json["betOutcome"].asString();
    if (json.isMember("profit"))
        profit = json["profit"].asDouble();
    if (json.isMember("customerOrderRef"))
        customerOrderRef = json["customerOrderRef"].asString();
    if (json.isMember("betCount"))
        betCount = json["betCount"].asInt();
    if (json.isMember("selectionId"))
        selectionId = json["selectionId"].asInt64();
    if (json.isMember("customerOrderRef"))
        customerOrderRef = json["customerOrderRef"].asString();
    if (json.isMember("marketId"))
        marketId = json["marketId"].asString();
    if (json.isMember("eventTypeId"))
        eventTypeId = json["eventTypeId"].asString();
    if (json.isMember("eventId"))
        eventId = json["eventId"].asString();
    if (json.isMember("betId"))
        betId = json["betId"].asString();
    if (json.isMember("handicap"))
        handicap = json["handicap"].asDouble();
    if (json.isMember("placedDate"))
        placedDate = json["placedDate"].asString();
    if (json.isMember("lastMatchedDate"))
        lastMatchedDate = json["lastMatchedDate"].asString();
    if (json.isMember("settledDate"))
        settledDate = json["settledDate"].asString();
    if (json.isMember("sizeSettled"))
        sizeSettled = json["sizeSettled"].asDouble();
    if (json.isMember("commission"))
        commission = json["commission"].asDouble();
    if (json.isMember("priceRequested"))
        priceRequested = json["priceRequested"].asDouble();
    if (json.isMember("priceMatched"))
        priceMatched = json["priceMatched"].asDouble();
    if (json.isMember("sizeCancelled"))
        sizeCancelled = json["sizeCancelled"].asDouble();
    if (json.isMember("priceReduced"))
        priceReduced = json["priceReduced"].asBool();
    if (json.isMember("itemDescription"))
        itemDescription = ItemDescription(json["itemDescription"]);

}
