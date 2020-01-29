//
// Created by scott on 29/01/2020.
//

#include "ReplaceExecutionReport.h"

ReplaceExecutionReport::ReplaceExecutionReport(Json::Value json) {
    if (json.isMember("customerRef"))
        customerRef = json["customerRef"].asString();
    status = json["status"].asString();
    if (json.isMember("errorCode"))
        errorCode = json["errorCode"].asString();
    if (json.isMember("marketId"))
        marketId = json["marketId"].asString();
    if (json.isMember("instructionReports")) {
        const Json::Value result = json["instructionReports"];
        std::vector<ReplaceInstructionReport > v;
        for (const auto & index : result)
        {
            v.emplace_back(ReplaceInstructionReport(index));
        }
        instructionReports = v;
    }
}
