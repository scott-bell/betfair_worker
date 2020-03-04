//
// Created by scott on 24/01/2020.
//

#include "ItemDescription.h"

namespace API {

    ItemDescription::ItemDescription(Json::Value json) {
        if (json.isMember("eventTypeDesc"))
            eventTypeDesc = json["eventTypeDesc"].asString();
        if (json.isMember("eventDesc"))
            eventDesc = json["eventDesc"].asString();
        if (json.isMember("marketDesc"))
            marketDesc = json["marketDesc"].asString();
        if (json.isMember("marketType"))
            marketType = json["marketType"].asString();
        if (json.isMember("marketStartTime"))
            marketStartTime = json["marketStartTime"].asString();
        if (json.isMember("runnerDesc"))
            runnerDesc = json["runnerDesc"].asString();
        if (json.isMember("numberOfWinners"))
            numberOfWinners = json["numberOfWinners"].asInt();
        if (json.isMember("eachWayDivisor"))
            eachWayDivisor = json["eachWayDivisor"].asDouble();
    }

}