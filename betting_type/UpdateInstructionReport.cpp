//
// Created by scott on 28/01/2020.
//

#include "UpdateInstructionReport.h"

UpdateInstructionReport::UpdateInstructionReport(Json::Value json) :
        status(json["status"].asString()),
        instruction(UpdateInstruction(json["instruction"]))
{
    if (json.isMember("errorCode"))
        errorCode = json["errorCode"].asString();
}
