//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_PLACEINSTRUCTION_H
#define BETFAIR_WORKER_PLACEINSTRUCTION_H


#include <string>
#include <optional>
#include <boost/property_tree/ptree.hpp>
#include <jsoncpp/json/value.h>
#include "LimitOrder.h"
#include "LimitOnCloseOrder.h"
#include "MarketOnCloseOrder.h"

struct PlaceInstruction {
    std::string                         orderType;
    long                                selectionId;
    std::optional<double>               handicap;
    std::string                         side;
    std::optional<LimitOrder>           limitOrder;
    std::optional<LimitOnCloseOrder>    limitOnCloseOrder;
    std::optional<MarketOnCloseOrder>   marketOnCloseOrder;
    std::optional<std::string>          customerOrderRef;

    [[nodiscard]] boost::property_tree::ptree ptree() const;
    explicit PlaceInstruction(Json::Value json);
    PlaceInstruction(std::string orderType,long selectionId, std::optional<double> handicap, std::string side,std::optional<LimitOrder> limitOrder,std::optional<LimitOnCloseOrder> limitOnCloseOrder, std::optional<MarketOnCloseOrder> marketOnCloseOrder,std::optional <std::string> customerOrderRef);
};


#endif //BETFAIR_WORKER_PLACEINSTRUCTION_H
