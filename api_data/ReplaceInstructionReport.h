//
// Created by scott on 29/01/2020.
//

#ifndef SXCLIENT_REPLACEINSTRUCTIONREPORT_H
#define SXCLIENT_REPLACEINSTRUCTIONREPORT_H


#include <string>
#include <optional>
#include "PlaceInstructionReport.h"
#include "CancelInstructionReport.h"
namespace API {

    struct ReplaceInstructionReport {
        std::string status;
        std::optional<std::string> errorCode;
        std::optional<CancelInstructionReport> cancelInstructionReport;
        std::optional<PlaceInstructionReport> placeInstructionReport;

        explicit ReplaceInstructionReport(Json::Value json);
    };
}

#endif //SXCLIENT_REPLACEINSTRUCTIONREPORT_H