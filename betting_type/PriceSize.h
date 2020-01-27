//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_PRICESIZE_H
#define BETFAIR_WORKER_PRICESIZE_H


#include <jsoncpp/json/json.h>

struct PriceSize {
    double price;
    double size;
    explicit PriceSize(Json::Value json);
};


#endif //BETFAIR_WORKER_PRICESIZE_H
