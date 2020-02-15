//
// Created by scott on 23/01/2020.
//

#ifndef SXCLIENT_COMPETITION_H
#define SXCLIENT_COMPETITION_H

#include <string>
#include <optional>
#include <jsoncpp/json/value.h>

namespace API {
    struct Competition {
        std::optional<std::string> id;
        std::optional<std::string> name;

        explicit Competition(Json::Value json);
    };
}

#endif //SXCLIENT_COMPETITION_H
