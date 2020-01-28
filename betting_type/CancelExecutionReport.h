//
// Created by scott on 28/01/2020.
//

#ifndef BETFAIR_WORKER_CANCELEXECUTIONREPORT_H
#define BETFAIR_WORKER_CANCELEXECUTIONREPORT_H


#include <string>
#include <optional>
#include <vector>
#include <jsoncpp/json/json.h>
#include "CancelInstructionReport.h"

struct CancelExecutionReport {
    std::optional<std::string> customerRef;
    std::string status;
    std::optional<std::string> errorCode;
    std::optional<std::string> marketId;
    std::optional<std::vector<CancelInstructionReport>> instructionReports;

    CancelExecutionReport() = default;
    explicit CancelExecutionReport(Json::Value json);
};


#endif //BETFAIR_WORKER_CANCELEXECUTIONREPORT_H
