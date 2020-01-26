//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_PLACEEXECUTIONREPORT_H
#define BETFAIR_WORKER_PLACEEXECUTIONREPORT_H


#include <string>
#include <vector>
#include <optional>
#include <jsoncpp/json/value.h>
#include "PlaceInstructionReport.h"

struct PlaceExecutionReport {
    std::optional<std::string> customerRef;
    std::string status;
    std::optional<std::string> errorCode;
    std::optional<std::string> marketId;
    std::optional<std::vector<PlaceInstructionReport> > instructionReports;

    PlaceExecutionReport() = default;
    explicit PlaceExecutionReport(Json::Value json);
};


#endif //BETFAIR_WORKER_PLACEEXECUTIONREPORT_H
