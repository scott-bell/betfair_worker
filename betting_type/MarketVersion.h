//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETVERSION_H
#define BETFAIR_WORKER_MARKETVERSION_H

#include <optional>
#include <boost/property_tree/ptree.hpp>

struct MarketVersion {
    long version;
    [[nodiscard]] boost::property_tree::ptree ptree() const;
};


#endif //BETFAIR_WORKER_MARKETVERSION_H
