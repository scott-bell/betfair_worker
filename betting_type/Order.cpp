//
// Created by scott on 24/01/2020.
//

#include "Order.h"

Order::Order(Json::Value json) {
    betId = json["betId"].asString();
    orderType = json["orderType"].asString();
    status = json["status"].asString();
    persistenceType = json["persistenceType"].asString();
    side = json["side"].asString();
    price = json["price"].asDouble();
    size = json["size"].asDouble();
    bspLiability = json["bspLiability"].asDouble();
    placedDate = json["placedDate"].asString();
    if (json.isMember("avgPriceMatched"))
        avgPriceMatched = json["avgPriceMatched"].asDouble();
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
    if (json.isMember("customerOrderRef"))
        customerOrderRef = json["customerOrderRef"].asString();
    if (json.isMember("customerStrategyRef"))
        customerStrategyRef = json["customerStrategyRef"].asString();
}
