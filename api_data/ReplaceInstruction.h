//
// Created by scott on 29/01/2020.
//

#ifndef SXCLIENT_REPLACEINSTRUCTION_H
#define SXCLIENT_REPLACEINSTRUCTION_H

#include <string>
#include <jsoncpp/json/json.h>
namespace API {

    struct ReplaceInstruction {
        std::string betId;
        double newPrice;

        ReplaceInstruction(std::string betId, double newPrice);

        [[nodiscard]] Json::Value json() const;

        explicit ReplaceInstruction(Json::Value json);
    };
}

#endif //SXCLIENT_REPLACEINSTRUCTION_H
