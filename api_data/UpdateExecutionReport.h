//
// Created by scott on 28/01/2020.
//

#ifndef SXCLIENT_UPDATEEXECUTIONREPORT_H
#define SXCLIENT_UPDATEEXECUTIONREPORT_H


#include <vector>
#include <string>
#include <jsoncpp/json/json.h>
#include "UpdateInstructionReport.h"
namespace API {

    struct UpdateExecutionReport {
        std::optional<std::string> customerRef;
        std::string status;
        std::optional<std::string> errorCode;
        std::optional<std::string> marketId;
        std::optional<std::vector<UpdateInstructionReport>> instructionReports;

        UpdateExecutionReport() = default;

        explicit UpdateExecutionReport(Json::Value json);

    };
}

#endif //SXCLIENT_UPDATEEXECUTIONREPORT_H
