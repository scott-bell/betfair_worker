//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_ORDER_H
#define BETFAIR_WORKER_ORDER_H


#include <string>
#include <optional>
#include <jsoncpp/json/json.h>

struct Order {
    std::string betId;
    std::string orderType;
    std::string status;
    std::string persistenceType;
    std::string side;
    double price;
    double size;
    double bspLiability;
    std::string placedDate;
    std::optional<double> avgPriceMatched;
    std::optional<double> sizeMatched;
    std::optional<double> sizeRemaining;
    std::optional<double> sizeLapsed;
    std::optional<double> sizeCancelled;
    std::optional<double> sizeVoided;
    std::optional<std::string> customerOrderRef;
    std::optional<std::string> customerStrategyRef;

    explicit Order(Json::Value json);

};


#endif //BETFAIR_WORKER_ORDER_H
