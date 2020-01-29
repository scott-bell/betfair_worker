//
// Created by scott on 28/01/2020.
//

#include "UpdateInstruction.h"

boost::property_tree::ptree UpdateInstruction::ptree() const {
    boost::property_tree::ptree tree;

    tree.put("betId",betId);
    tree.put("newPersistenceType",newPersistenceType);

    return tree;
}

UpdateInstruction::UpdateInstruction(Json::Value json) {
    if (json.isMember("betId"))
        betId = json["betId"].asString();
    if (json.isMember("newPersistenceType"))
        newPersistenceType = json["newPersistenceType"].asString();
}

UpdateInstruction::UpdateInstruction(std::string betId, std::string newPersistenceType):
    betId(betId), newPersistenceType(newPersistenceType)
{

}
