//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_EXCHANGEPRICES_H
#define SXCLIENT_EXCHANGEPRICES_H


#include <vector>
#include <optional>
#include "PriceSize.h"
namespace API {

    struct ExchangePrices {

        std::optional<std::vector<PriceSize>> availableToBack;
        std::optional<std::vector<PriceSize>> availableToLay;
        std::optional<std::vector<PriceSize>> tradedVolume;

        explicit ExchangePrices(Json::Value json);

    };
}

#endif //SXCLIENT_EXCHANGEPRICES_H
