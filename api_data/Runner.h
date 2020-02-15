//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_RUNNER_H
#define SXCLIENT_RUNNER_H

#include <string>
#include <optional>
#include <vector>
#include <map>
#include <jsoncpp/json/json.h>
#include "Order.h"
#include "Match.h"
#include "StartingPrices.h"
#include "ExchangePrices.h"

namespace API {
    struct Runner {
        long selectionId;
        double handicap;
        std::string status;
        std::optional<double> adjustmentFactor;
        std::optional<double> lastPriceTraded;
        std::optional<double> totalMatched;
        std::optional<std::string> removalDate;
        std::optional<StartingPrices> sp;
        std::optional<ExchangePrices> ex;
        std::optional<std::vector<Order>> orders;
        std::optional<std::vector<Match>> matches;
        std::optional<std::map<std::string, Match>> matchesByStrategy;

        explicit Runner(Json::Value json);

    };
}

#endif //SXCLIENT_RUNNER_H
