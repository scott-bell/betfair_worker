//
// Created by scott on 29/01/2020.
//

#include "ReplaceInstructionReport.h"

namespace API {
    ReplaceInstructionReport::ReplaceInstructionReport(Json::Value json) {
        status = json["status"].asString();
        if (json.isMember("errorCode"))
            errorCode = json["errorCode"].asString();
        if (json.isMember("cancelInstructionReport"))
            cancelInstructionReport = CancelInstructionReport(json["cancelInstructionReport"]);
        if (json.isMember("placeInstructionReport"))
            placeInstructionReport = PlaceInstructionReport(json["placeInstructionReport"]);

    }
}