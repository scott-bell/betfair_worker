//
// Created by scott on 28/01/2020.
//

#include "CancelInstruction.h"

#include <utility>


boost::property_tree::ptree CancelInstruction::ptree() const {
    boost::property_tree::ptree tree;
    if (betId.has_value())
        tree.put("betId",betId.value());
    if (sizeReduction.has_value())
        tree.put("sizeReduction",sizeReduction.value());
    return tree;
}

CancelInstruction::CancelInstruction(Json::Value json) {
    if (json.isMember("betId"))
        betId = json["betId"].asString();
    if (json.isMember("sizeReduction"))
        sizeReduction = json["sizeReduction"].asDouble();
}

CancelInstruction::CancelInstruction(std::optional<std::string> betId, std::optional<double> sizeReduction):
    betId(std::move(std::move(betId))), sizeReduction(std::move(sizeReduction))
{
}