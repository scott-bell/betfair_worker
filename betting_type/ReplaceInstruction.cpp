//
// Created by scott on 29/01/2020.
//

#include <boost/property_tree/ptree.hpp>
#include <utility>
#include "ReplaceInstruction.h"

boost::property_tree::ptree ReplaceInstruction::ptree() const {
    boost::property_tree::ptree tree;

    tree.put("betId",betId);
    tree.put("newPrice",newPrice);

    return tree;
}

ReplaceInstruction::ReplaceInstruction(Json::Value json) {
    if (json.isMember("betId"))
        betId = json["betId"].asString();
    if (json.isMember("newPrice"))
        newPrice = json["newPrice"].asDouble();
}

ReplaceInstruction::ReplaceInstruction(std::string betId, double newPrice):
        betId(std::move(betId)), newPrice(newPrice)
{

}