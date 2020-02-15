//
// Created by scott on 29/01/2020.
//

#include <utility>
#include "ReplaceInstruction.h"

namespace API {

    Json::Value ReplaceInstruction::json() const {
        Json::Value json;
        json["betId"] = betId;
        json["newPrice"] = newPrice;
        return json;
    }

    ReplaceInstruction::ReplaceInstruction(Json::Value json) {
        if (json.isMember("betId"))
            betId = json["betId"].asString();
        if (json.isMember("newPrice"))
            newPrice = json["newPrice"].asDouble();
    }

    ReplaceInstruction::ReplaceInstruction(std::string betId, double newPrice) :
            betId(std::move(betId)), newPrice(newPrice) {

    }

}
