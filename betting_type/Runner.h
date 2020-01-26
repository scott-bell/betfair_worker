//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_RUNNER_H
#define BETFAIR_WORKER_RUNNER_H

#include <string>
#include <optional>
#include <vector>
#include <map>
#include "Order.h"
#include "Match.h"
#include "StartingPrices.h"
#include "ExchangePrices.h"

struct Runner {
    unsigned long selectionId;
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

};


#endif //BETFAIR_WORKER_RUNNER_H
