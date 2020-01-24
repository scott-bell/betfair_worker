//
// Created by scott on 23/01/2020.
//

#include "Event.h"

Event::Event(Json::Value json) {
    if (json.isMember("id"))
        id = json["id"].asString();
    if (json.isMember("name"))
        name = json["name"].asString();
    if (json.isMember("countryCode"))
        countryCode = json["countryCode"].asString();
    if (json.isMember("timezone"))
        timezone = json["timezone"].asString();
    if (json.isMember("venue"))
        venue = json["venue"].asString();
    if (json.isMember("openDate"))
        openDate = json["openDate"].asString();

}
