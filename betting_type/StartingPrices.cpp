//
// Created by scott on 24/01/2020.
//

#include "StartingPrices.h"

StartingPrices::StartingPrices(Json::Value json) {
    if (json.isMember("nearPrice"))
        nearPrice = json["nearPrice"].asDouble();
    if (json.isMember("farPrice"))
        farPrice = json["farPrice"].asDouble();
    if (json.isMember("backStakeTaken")) {
        const Json::Value result = json["backStakeTaken"];
        std::vector<PriceSize> v;
        for (const auto & index : result)
        {
            v.emplace_back(PriceSize(index));
        }
        backStakeTaken = v;
    }
    if (json.isMember("layLiabilityTaken")) {
        const Json::Value result = json["layLiabilityTaken"];
        std::vector<PriceSize> v;
        for (const auto & index : result)
        {
            v.emplace_back(PriceSize(index));
        }
        layLiabilityTaken = v;
    }
    if (json.isMember("actualSP"))
        actualSP = json["actualSP"].asDouble();


}
