//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_STARTINGPRICES_H
#define BETFAIR_WORKER_STARTINGPRICES_H


#include <vector>
#include <optional>
#include <jsoncpp/json/json.h>
#include "PriceSize.h"

struct StartingPrices {
    std::optional<double> nearPrice;
    std::optional<double> farPrice;
    std::optional<std::vector<PriceSize>> backStakeTaken;
    std::optional<std::vector<PriceSize>> layLiabilityTaken;
    double actualSP;

    explicit StartingPrices(Json::Value json);

};


#endif //BETFAIR_WORKER_STARTINGPRICES_H
