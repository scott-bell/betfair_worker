//
// Created by scott on 28/01/2020.
//

#ifndef SXCLIENT_CANCELINSTRUCTIONREPORT_H
#define SXCLIENT_CANCELINSTRUCTIONREPORT_H

#include <string>
#include <optional>
#include <jsoncpp/json/json.h>
#include "CancelInstruction.h"
namespace API {

    struct CancelInstructionReport {
        std::string status;
        std::optional<std::string> errorCode;
        std::optional<CancelInstruction> instruction;
        double sizeCancelled;
        std::optional<std::string> cancelledDate;

        explicit CancelInstructionReport(Json::Value json);
    };
}

#endif //SXCLIENT_CANCELINSTRUCTIONREPORT_H
