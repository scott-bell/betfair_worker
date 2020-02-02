//
// Created by scott on 28/01/2020.
//

#ifndef BETFAIR_WORKER_CANCELINSTRUCTION_H
#define BETFAIR_WORKER_CANCELINSTRUCTION_H

#include <string>
#include <optional>
#include <forward_list>
#include <jsoncpp/json/json.h>

struct CancelInstruction {
    std::optional<std::string> betId;
    std::optional<double> sizeReduction;

    [[nodiscard]] Json::Value json() const;
    CancelInstruction(std::optional<std::string> betId, std::optional<double> sizeReduction);
    explicit CancelInstruction(Json::Value json);
};

#endif //BETFAIR_WORKER_CANCELINSTRUCTION_H
