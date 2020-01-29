//
// Created by scott on 29/01/2020.
//

#ifndef BETFAIR_WORKER_REPLACEEXECUTIONREPORT_H
#define BETFAIR_WORKER_REPLACEEXECUTIONREPORT_H

#include <optional>
#include <string>
#include <vector>
#include "ReplaceInstructionReport.h"

struct ReplaceExecutionReport {
    std::optional<std::string> customerRef;
    std::string status;
    std::optional<std::string> errorCode;
    std::optional<std::string> marketId;
    std::optional<std::vector<ReplaceInstructionReport>> instructionReports;
    ReplaceExecutionReport() = default;
    explicit ReplaceExecutionReport(Json::Value json);
};


#endif //BETFAIR_WORKER_REPLACEEXECUTIONREPORT_H
