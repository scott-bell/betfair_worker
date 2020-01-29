//
// Created by scott on 28/01/2020.
//

#ifndef BETFAIR_WORKER_UPDATEINSTRUCTION_H
#define BETFAIR_WORKER_UPDATEINSTRUCTION_H

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <jsoncpp/json/json.h>

struct UpdateInstruction {
    std::string betId;
    std::string newPersistenceType;
    [[nodiscard]] boost::property_tree::ptree ptree() const;
    UpdateInstruction(std::string betId, std::string newPersistenceType);
    explicit UpdateInstruction(Json::Value json);
};


#endif //BETFAIR_WORKER_UPDATEINSTRUCTION_H
