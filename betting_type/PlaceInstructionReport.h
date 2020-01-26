//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_PLACEINSTRUCTIONREPORT_H
#define BETFAIR_WORKER_PLACEINSTRUCTIONREPORT_H

#include <string>
#include <jsoncpp/json/value.h>
#include "PlaceInstruction.h"

struct PlaceInstructionReport {
    std::string status;
    std::optional<std::string> errorCode;
    std::optional<std::string> orderStatus;
    PlaceInstruction instruction;
    std::optional<std::string> betId;
    std::optional<std::string> placedDate;
    std::optional<double> averagePriceMatched;
    std::optional<double> sizeMatched;

    explicit PlaceInstructionReport(Json::Value json);


};


#endif //BETFAIR_WORKER_PLACEINSTRUCTIONREPORT_H
