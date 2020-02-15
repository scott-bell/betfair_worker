//
// Created by scott on 24/01/2020.
//

#include "PlaceInstruction.h"

#include <utility>

namespace API {
    Json::Value PlaceInstruction::json() const {
        Json::Value json;
        json["orderType"] = orderType;
        json["selectionId"] = std::to_string(selectionId);
        if (handicap.has_value())
            json["handicap"] = handicap.value();
        json["side"] = side;
        if (limitOrder.has_value())
            json["limitOrder"] = limitOrder.value().json();
        if (limitOnCloseOrder.has_value())
            json["limitOnCloseOrder"] = limitOnCloseOrder.value().json();
        if (marketOnCloseOrder.has_value())
            json["marketOnCloseOrder"] = marketOnCloseOrder.value().json();
        if (customerOrderRef.has_value())
            json["customerOrderRef"] = customerOrderRef.value();
        return json;
    }

    PlaceInstruction::PlaceInstruction(Json::Value json) {
        orderType = json["orderType"].asString();
        selectionId = json["selectionId"].asInt();
        if (json.isMember("handicap"))
            handicap = json["handicap"].asDouble();
        side = json["side"].asString();
        if (json.isMember("limitOrder"))
            limitOrder = LimitOrder(json["limitOrder"]);
        if (json.isMember("limitOnCloseOrder"))
            limitOnCloseOrder = LimitOnCloseOrder(json["limitOnCloseOrder"]);
        if (json.isMember("marketOnCloseOrder"))
            marketOnCloseOrder = MarketOnCloseOrder(json["limitOrder"]);


    }

    PlaceInstruction::PlaceInstruction(std::string orderType, long selectionId, std::optional<double> handicap,
                                       std::string side, std::optional<LimitOrder> limitOrder,
                                       std::optional<LimitOnCloseOrder> limitOnCloseOrder,
                                       std::optional<MarketOnCloseOrder> marketOnCloseOrder,
                                       std::optional<std::string> customerOrderRef) :
            orderType(std::move(orderType)), selectionId(selectionId), handicap(std::move(handicap)),
            side(std::move(side)), limitOrder(std::move(limitOrder)), limitOnCloseOrder(std::move(limitOnCloseOrder)),
            marketOnCloseOrder(std::move(marketOnCloseOrder)), customerOrderRef(std::move(customerOrderRef)) {

    }
}

