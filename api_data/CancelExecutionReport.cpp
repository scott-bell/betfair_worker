//
// Created by scott on 28/01/2020.
//

#include "CancelExecutionReport.h"
namespace API {

    CancelExecutionReport::CancelExecutionReport(Json::Value json) {
        if (json.isMember("customerRef"))
            customerRef = json["customerRef"].asString();
        status = json["status"].asString();
        if (json.isMember("errorCode"))
            errorCode = json["errorCode"].asString();
        if (json.isMember("marketId"))
            marketId = json["marketId"].asString();
        if (json.isMember("instructionReports")) {
            const Json::Value result = json["instructionReports"];
            std::vector<CancelInstructionReport> v;
            for (const auto &index : result) {
                v.emplace_back(CancelInstructionReport(index));
            }
            instructionReports = v;
        }

    }
}