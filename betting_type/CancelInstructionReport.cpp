//
// Created by scott on 28/01/2020.
//

#include "CancelInstructionReport.h"

CancelInstructionReport::CancelInstructionReport(Json::Value json) {
    status = json["status"].asString();
    if (json.isMember("errorCode"))
        errorCode = json["errorCode"].asString();
    if (json.isMember("instruction"))
        instruction = CancelInstruction(json["instruction"]);
    sizeCancelled = json["sizeCancelled"].asDouble();
    if (json.isMember("cancelledDate"))
        cancelledDate = json["cancelledDate"].asString();
}
