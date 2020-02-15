//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_LIMITORDER_H
#define SXCLIENT_LIMITORDER_H


#include <string>
#include <optional>
#include <jsoncpp/json/value.h>
namespace API {

    struct LimitOrder {
        double size;
        double price;
        std::string persistenceType;
        std::optional<std::string> timeInForce;
        std::optional<double> minFillSize;
        std::optional<std::string> betTargetType;
        std::optional<double> betTargetSize;

        [[nodiscard]] Json::Value json() const;

        LimitOrder(double size, double price, std::string persistenceType, std::optional<std::string> timeInForce,
                   std::optional<double> minFillSize, std::optional<std::string> betTargetType,
                   std::optional<double> betTargetSize);

        explicit LimitOrder(Json::Value json);

    };
}

#endif //SXCLIENT_LIMITORDER_H
