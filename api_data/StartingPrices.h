//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_STARTINGPRICES_H
#define SXCLIENT_STARTINGPRICES_H


#include <vector>
#include <optional>
#include <jsoncpp/json/json.h>
#include "PriceSize.h"
namespace API {

    struct StartingPrices {
        std::optional<double> nearPrice;
        std::optional<double> farPrice;
        std::optional<std::vector<PriceSize>> backStakeTaken;
        std::optional<std::vector<PriceSize>> layLiabilityTaken;
        double actualSP;

        explicit StartingPrices(Json::Value json);

    };
}

#endif //SXCLIENT_STARTINGPRICES_H
