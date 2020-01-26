//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_EXCHANGEPRICES_H
#define BETFAIR_WORKER_EXCHANGEPRICES_H


#include <vector>
#include <optional>
#include "PriceSize.h"

class ExchangePrices {

    std::optional<std::vector<PriceSize>> availableToBack;
    std::optional<std::vector<PriceSize>> availableToLay;
    std::optional<std::vector<PriceSize>> tradedVolume;

};


#endif //BETFAIR_WORKER_EXCHANGEPRICES_H
