//
// Created by scott on 23/01/2020.
//

#include "MarketCatalogue.h"

namespace API {
    MarketCatalogue::MarketCatalogue(Json::Value json) {
        marketId = json["marketId"].asString();
        marketName = json["marketName"].asString();
        if (json.isMember("marketStartTime"))
            marketStartTime = json["marketStartTime"].asString();
        if (json.isMember("description"))
            description = MarketDescription(json["description"]);
        if (json.isMember("totalMatched"))
            totalMatched = json["totalMatched"].asDouble();
        if (json.isMember("runners")) {
            const Json::Value result = json["runners"];
            std::vector<RunnerCatalog> v;
            for (const auto &index : result) {
                v.emplace_back(RunnerCatalog(index));
            }
            runners = v;
        }
        if (json.isMember("eventType"))
            eventType = EventType(json["eventType"]);
        if (json.isMember("competition"))
            competition = Competition(json["competition"]);
        if (json.isMember("event"))
            event = Event(json["event"]);

    }
}