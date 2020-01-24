//
// Created by scott on 23/01/2020.
//

#ifndef BETFAIR_WORKER_PRICELADDERDESCRIPTION_H
#define BETFAIR_WORKER_PRICELADDERDESCRIPTION_H

#include <string>
#include <jsoncpp/json/value.h>

struct PriceLadderDescription {
    std::string type;   // PriceLadderType enum


    explicit PriceLadderDescription(Json::Value json);
};


#endif //BETFAIR_WORKER_PRICELADDERDESCRIPTION_H
