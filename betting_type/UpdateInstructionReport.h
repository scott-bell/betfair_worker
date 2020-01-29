//
// Created by scott on 28/01/2020.
//

#ifndef BETFAIR_WORKER_UPDATEINSTRUCTIONREPORT_H
#define BETFAIR_WORKER_UPDATEINSTRUCTIONREPORT_H


#include "UpdateInstruction.h"
#include <optional>
#include <string>
#include <jsoncpp/json/json.h>

struct UpdateInstructionReport {
    std::string status;
    std::optional<std::string> errorCode;
    UpdateInstruction instruction;
    explicit UpdateInstructionReport(Json::Value json);
};


#endif //BETFAIR_WORKER_UPDATEINSTRUCTIONREPORT_H
