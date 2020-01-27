//
// Created by scott on 24/01/2020.
//

#include "ExchangePrices.h"

ExchangePrices::ExchangePrices(Json::Value json) {
    if (json.isMember("availableToBack")) {
        const Json::Value result = json["availableToBack"];
        std::vector<PriceSize> v;
        for (const auto & index : result)
        {
            v.emplace_back(PriceSize(index));
        }
        availableToBack = v;
    }
    if (json.isMember("availableToLay")) {
        const Json::Value result = json["availableToLay"];
        std::vector<PriceSize> v;
        for (const auto & index : result)
        {
            v.emplace_back(PriceSize(index));
        }
        availableToLay = v;
    }
    if (json.isMember("tradedVolume")) {
        const Json::Value result = json["tradedVolume"];
        std::vector<PriceSize> v;
        for (const auto & index : result)
        {
            v.emplace_back(PriceSize(index));
        }
        tradedVolume = v;
    }
}
