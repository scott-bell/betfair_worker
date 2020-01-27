//
// Created by scott on 24/01/2020.
//

#include "Match.h"

Match::Match(Json::Value json) {
    if (json.isMember("betId"))
        betId = json["betId"].asString();
    if (json.isMember("matchId"))
        matchId = json["matchId"].asString();
    if (json.isMember("side"))
        side = json["side"].asString();
    if (json.isMember("price"))
        price = json["price"].asDouble();
    if (json.isMember("size"))
        size = json["size"].asDouble();
    if (json.isMember("matchDate"))
        matchDate = json["matchDate"].asString();

}
