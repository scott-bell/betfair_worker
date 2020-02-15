//
// Created by scott on 28/01/2020.
//

#ifndef SXCLIENT_CANCELEXECUTIONREPORT_H
#define SXCLIENT_CANCELEXECUTIONREPORT_H


#include <string>
#include <optional>
#include <vector>
#include <jsoncpp/json/json.h>
#include "CancelInstructionReport.h"
namespace API {

    struct CancelExecutionReport {
        std::optional<std::string> customerRef;
        std::string status;
        std::optional<std::string> errorCode;
        std::optional<std::string> marketId;
        std::optional<std::vector<CancelInstructionReport>> instructionReports;

        CancelExecutionReport() = default;

        explicit CancelExecutionReport(Json::Value json);
    };
}

#endif //SXCLIENT_CANCELEXECUTIONREPORT_H
