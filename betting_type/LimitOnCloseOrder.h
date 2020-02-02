//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_LIMITONCLOSEORDER_H
#define BETFAIR_WORKER_LIMITONCLOSEORDER_H


#include <jsoncpp/json/json.h>

struct LimitOnCloseOrder {
    double liability;
    double price;
    [[nodiscard]] Json::Value json() const;
    explicit LimitOnCloseOrder(Json::Value json);
};


#endif //BETFAIR_WORKER_LIMITONCLOSEORDER_H
