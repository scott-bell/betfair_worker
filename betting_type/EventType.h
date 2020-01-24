//
// Created by scott on 23/01/2020.
//

#ifndef BETFAIR_WORKER_EVENTTYPE_H
#define BETFAIR_WORKER_EVENTTYPE_H

#include <string>
#include <optional>
#include <jsoncpp/json/value.h>

struct EventType {
    std::optional<std::string> id;
    std::optional<std::string> name;

    explicit EventType(Json::Value json);


};


#endif //BETFAIR_WORKER_EVENTTYPE_H
