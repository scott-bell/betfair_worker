//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETONCLOSEORDER_H
#define BETFAIR_WORKER_MARKETONCLOSEORDER_H


#include <boost/property_tree/ptree.hpp>

struct MarketOnCloseOrder {
    double liability;
    [[nodiscard]] boost::property_tree::ptree ptree() const;
    explicit MarketOnCloseOrder(Json::Value json);

};


#endif //BETFAIR_WORKER_MARKETONCLOSEORDER_H
