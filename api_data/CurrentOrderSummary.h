//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_CURRENTORDERSUMMARY_H
#define SXCLIENT_CURRENTORDERSUMMARY_H

#include <string>
#include <optional>
#include "PriceSize.h"

namespace API {
    struct CurrentOrderSummary {

        std::string betId;
        std::string marketId;
        long selectionId;
        double handicap;
        PriceSize priceSize;
        double bspLiability;
        std::string side;
        std::string status;
        std::string persistenceType;
        std::string orderType;
        std::string placedDate;
        std::string matchedDate;
        std::optional<double> averagePriceMatched;
        std::optional<double> sizeMatched;
        std::optional<double> sizeRemaining;
        std::optional<double> sizeLapsed;
        std::optional<double> sizeCancelled;
        std::optional<double> sizeVoided;
        std::optional<std::string> regulatorAuthCode;
        std::optional<std::string> regulatorCode;
        std::optional<std::string> customerOrderRef;
        std::optional<std::string> customerStrategyRef;


        explicit CurrentOrderSummary(Json::Value json);

    };
}

#endif //SXCLIENT_CURRENTORDERSUMMARY_H
