//
// Created by scott on 28/01/2020.
//

#include "CancelInstruction.h"

#include <utility>

namespace API {

    Json::Value CancelInstruction::json() const {
        Json::Value json;
        if (betId.has_value())
            json["betId"] = betId.value();
        if (sizeReduction.has_value())
            json["sizeReduction"] = sizeReduction.value();
        return json;
    }

    CancelInstruction::CancelInstruction(Json::Value json) {
        if (json.isMember("betId"))
            betId = json["betId"].asString();
        if (json.isMember("sizeReduction"))
            sizeReduction = json["sizeReduction"].asDouble();
    }

    CancelInstruction::CancelInstruction(std::optional<std::string> betId, std::optional<double> sizeReduction) :
            betId(std::move(std::move(betId))), sizeReduction(std::move(sizeReduction)) {
    }
}