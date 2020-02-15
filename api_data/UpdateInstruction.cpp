//
// Created by scott on 28/01/2020.
//

#include "UpdateInstruction.h"
namespace API {

    Json::Value UpdateInstruction::json() const {
        Json::Value json;
        json["betId"] = betId;
        json["newPersistenceType"] = newPersistenceType;
        return json;
    }

    UpdateInstruction::UpdateInstruction(Json::Value json) {
        if (json.isMember("betId"))
            betId = json["betId"].asString();
        if (json.isMember("newPersistenceType"))
            newPersistenceType = json["newPersistenceType"].asString();
    }

    UpdateInstruction::UpdateInstruction(std::string betId, std::string newPersistenceType) :
            betId(betId), newPersistenceType(newPersistenceType) {

    }
}
