//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_LIMITORDER_H
#define BETFAIR_WORKER_LIMITORDER_H


#include <string>
#include <optional>
#include <jsoncpp/json/value.h>

struct LimitOrder {
    double size;
    double price;
    std::string persistenceType;
    std::optional<std::string> timeInForce;
    std::optional<double> minFillSize;
    std::optional<std::string> betTargetType;
    std::optional<double> betTargetSize;

    [[nodiscard]] Json::Value json() const;
    LimitOrder(double size, double price, std::string persistenceType, std::optional<std::string> timeInForce, std::optional<double> minFillSize, std::optional<std::string> betTargetType, std::optional<double> betTargetSize);
    explicit LimitOrder(Json::Value json);

};


#endif //BETFAIR_WORKER_LIMITORDER_H
