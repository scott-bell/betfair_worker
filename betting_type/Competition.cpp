//
// Created by scott on 23/01/2020.
//

#include "Competition.h"

Competition::Competition(Json::Value json) {
    if (json.isMember("id"))
        id = json["id"].asString();
    if (json.isMember("name"))
        name = json["name"].asString();
}
