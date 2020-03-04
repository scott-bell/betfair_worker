//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_CLEAREDORDERSUMMARY_H
#define SXCLIENT_CLEAREDORDERSUMMARY_H

#include <string>
#include <optional>
#include <jsoncpp/json/value.h>
#include "ItemDescription.h"

namespace API {

    struct ClearedOrderSummary {
        std::optional<std::string> side;
        std::optional<std::string> orderType;
        std::optional<std::string> persistenceType;
        std::optional<std::string> customerStrategyRef;
        std::optional<std::string> betOutcome;
        std::optional<double> profit;
        std::optional<std::string> customerOrderRef;
        std::optional<int> betCount;
        std::optional<long> selectionId;
        std::optional<std::string> marketId;
        std::optional<std::string> eventTypeId;
        std::optional<std::string> eventId;
        std::optional<std::string> betId;
        std::optional<double> handicap;
        std::optional<std::string> placedDate;
        std::optional<std::string> lastMatchedDate;
        std::optional<std::string> settledDate;
        std::optional<double> sizeSettled;
        std::optional<double> commission;
        std::optional<double> priceRequested;
        std::optional<double> priceMatched;
        std::optional<double> sizeCancelled;
        std::optional<bool> priceReduced;
        std::optional<ItemDescription> itemDescription;

        explicit ClearedOrderSummary(Json::Value json);

    };
}

#endif //SXCLIENT_CLEAREDORDERSUMMARY_H
