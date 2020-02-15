//
// Created by scott on 23/01/2020.
//

#ifndef SXCLIENT_EVENT_H
#define SXCLIENT_EVENT_H

#include <string>

#include <jsoncpp/json/value.h>
namespace  API {
    struct Event {
        std::optional<std::string> id;
        std::optional<std::string> name;
        std::optional<std::string> countryCode;
        std::optional<std::string> timezone;
        std::optional<std::string> venue;
        std::optional<std::string> openDate;

        explicit Event(Json::Value json);
    };
}

#endif //SXCLIENT_EVENT_H
