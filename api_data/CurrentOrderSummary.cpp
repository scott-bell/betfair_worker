//
// Created by scott on 24/01/2020.
//

#include "CurrentOrderSummary.h"

namespace API {

    CurrentOrderSummary::CurrentOrderSummary(Json::Value json) :
            betId(json["betId"].asString()),
            marketId(json["marketId"].asString()),
            selectionId(json["selectionId"].asInt64()),
            handicap(json["handicap"].asDouble()),
            priceSize(PriceSize(json["priceSize"])),
            bspLiability(json["bspLiability"].asDouble()),
            side(json["side"].asString()),
            status(json["status"].asString()),
            persistenceType(json["persistenceType"].asString()),
            orderType(json["orderType"].asString()),
            matchedDate(json["matchedDate"].asString()) {
        if (json.isMember("averagePriceMatched"))
            averagePriceMatched = json["averagePriceMatched"].asDouble();
        if (json.isMember("sizeMatched"))
            sizeMatched = json["sizeMatched"].asDouble();
        if (json.isMember("sizeRemaining"))
            sizeRemaining = json["sizeRemaining"].asDouble();
        if (json.isMember("sizeLapsed"))
            sizeLapsed = json["sizeLapsed"].asDouble();
        if (json.isMember("sizeCancelled"))
            sizeCancelled = json["sizeCancelled"].asDouble();
        if (json.isMember("sizeVoided"))
            sizeVoided = json["sizeVoided"].asDouble();
        if (json.isMember("regulatorAuthCode"))
            regulatorAuthCode = json["regulatorAuthCode"].asString();
        if (json.isMember("regulatorCode"))
            regulatorCode = json["regulatorCode"].asString();
        if (json.isMember("customerOrderRef"))
            customerOrderRef = json["customerOrderRef"].asString();
        if (json.isMember("customerStrategyRef"))
            customerStrategyRef = json["customerStrategyRef"].asString();

    }
}