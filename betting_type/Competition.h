//
// Created by scott on 23/01/2020.
//

#ifndef BETFAIR_WORKER_COMPETITION_H
#define BETFAIR_WORKER_COMPETITION_H

#include <string>
#include <optional>
#include <jsoncpp/json/value.h>

struct Competition {
    std::optional<std::string> id;
    std::optional<std::string> name;

    explicit Competition(Json::Value json);
};


#endif //BETFAIR_WORKER_COMPETITION_H
