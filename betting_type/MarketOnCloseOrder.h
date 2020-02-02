//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETONCLOSEORDER_H
#define BETFAIR_WORKER_MARKETONCLOSEORDER_H

struct MarketOnCloseOrder {
    double liability;
    [[nodiscard]] Json::Value json() const;
    explicit MarketOnCloseOrder(Json::Value json);

};


#endif //BETFAIR_WORKER_MARKETONCLOSEORDER_H
