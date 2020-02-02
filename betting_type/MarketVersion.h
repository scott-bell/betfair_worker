//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETVERSION_H
#define BETFAIR_WORKER_MARKETVERSION_H

#include <optional>
#include <jsoncpp/json/json.h>

struct MarketVersion {
    long version;
    [[nodiscard]] Json::Value json() const;
};


#endif //BETFAIR_WORKER_MARKETVERSION_H
