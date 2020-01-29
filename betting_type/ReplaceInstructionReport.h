//
// Created by scott on 29/01/2020.
//

#ifndef BETFAIR_WORKER_REPLACEINSTRUCTIONREPORT_H
#define BETFAIR_WORKER_REPLACEINSTRUCTIONREPORT_H


#include <string>
#include <optional>
#include "PlaceInstructionReport.h"
#include "CancelInstructionReport.h"

struct ReplaceInstructionReport {
    std::string status;
    std::optional<std::string> errorCode;
    std::optional<CancelInstructionReport> cancelInstructionReport;
    std::optional<PlaceInstructionReport> placeInstructionReport;
    explicit ReplaceInstructionReport(Json::Value json);
};


#endif //BETFAIR_WORKER_REPLACEINSTRUCTIONREPORT_H