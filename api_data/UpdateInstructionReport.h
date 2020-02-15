//
// Created by scott on 28/01/2020.
//

#ifndef SXCLIENT_UPDATEINSTRUCTIONREPORT_H
#define SXCLIENT_UPDATEINSTRUCTIONREPORT_H


#include "UpdateInstruction.h"
#include <optional>
#include <string>
#include <jsoncpp/json/json.h>
namespace API {

    struct UpdateInstructionReport {
        std::string status;
        std::optional<std::string> errorCode;
        UpdateInstruction instruction;

        explicit UpdateInstructionReport(Json::Value json);
    };
}

#endif //SXCLIENT_UPDATEINSTRUCTIONREPORT_H
