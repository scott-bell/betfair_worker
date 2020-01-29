//
// Created by scott on 29/01/2020.
//

#ifndef BETFAIR_WORKER_REPLACEINSTRUCTION_H
#define BETFAIR_WORKER_REPLACEINSTRUCTION_H

#include <string>
#include <jsoncpp/json/json.h>
#include <boost/property_tree/ptree.hpp>

struct ReplaceInstruction {
    std::string betId;
    double newPrice;
    ReplaceInstruction(std::string betId, double newPrice);
    [[nodiscard]] boost::property_tree::ptree ptree() const;
    explicit ReplaceInstruction(Json::Value json);
};


#endif //BETFAIR_WORKER_REPLACEINSTRUCTION_H
