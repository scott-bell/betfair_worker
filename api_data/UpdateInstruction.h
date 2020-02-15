//
// Created by scott on 28/01/2020.
//

#ifndef SXCLIENT_UPDATEINSTRUCTION_H
#define SXCLIENT_UPDATEINSTRUCTION_H

#include <string>
#include <jsoncpp/json/json.h>

namespace API {
    struct UpdateInstruction {
        std::string betId;
        std::string newPersistenceType;

        [[nodiscard]] Json::Value json() const;

        UpdateInstruction(std::string betId, std::string newPersistenceType);

        explicit UpdateInstruction(Json::Value json);
    };
}

#endif //SXCLIENT_UPDATEINSTRUCTION_H
