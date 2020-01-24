//
// Created by scott on 23/01/2020.
//

#ifndef BETFAIR_WORKER_EVENT_H
#define BETFAIR_WORKER_EVENT_H

#include <string>

#include <jsoncpp/json/value.h>

struct Event {
    std::optional<std::string> id;
    std::optional<std::string> name;
    std::optional<std::string> countryCode;
    std::optional<std::string> timezone;
    std::optional<std::string> venue;
    std::optional<std::string> openDate;

    explicit Event(Json::Value json);
};


#endif //BETFAIR_WORKER_EVENT_H
