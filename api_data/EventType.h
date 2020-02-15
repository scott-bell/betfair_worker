//
// Created by scott on 23/01/2020.
//

#ifndef SXCLIENT_EVENTTYPE_H
#define SXCLIENT_EVENTTYPE_H

#include <string>
#include <optional>
#include <jsoncpp/json/value.h>

namespace API {

    struct EventType {
        std::optional<std::string> id;
        std::optional<std::string> name;

        explicit EventType(Json::Value json);
    };
}

#endif //SXCLIENT_EVENTTYPE_H
