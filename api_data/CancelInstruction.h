//
// Created by scott on 28/01/2020.
//

#ifndef SXCLIENT_CANCELINSTRUCTION_H
#define SXCLIENT_CANCELINSTRUCTION_H

#include <string>
#include <optional>
#include <forward_list>
#include <jsoncpp/json/json.h>
namespace API {

    struct CancelInstruction {
        std::optional<std::string> betId;
        std::optional<double> sizeReduction;

        [[nodiscard]] Json::Value json() const;

        CancelInstruction(std::optional<std::string> betId, std::optional<double> sizeReduction);

        explicit CancelInstruction(Json::Value json);
    };
}
#endif //SXCLIENT_CANCELINSTRUCTION_H
