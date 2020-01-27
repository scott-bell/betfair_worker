//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_MATCH_H
#define BETFAIR_WORKER_MATCH_H

#include <string>
#include <optional>
#include <jsoncpp/json/json.h>

struct Match {
    std::optional<std::string> betId;
    std::optional<std::string> matchId;
    std::string side;
    double price;
    double size;
    std::optional<std::string> matchDate;
    explicit Match(Json::Value json);

};


#endif //BETFAIR_WORKER_MATCH_H
