//
// Created by scott on 26/01/2020.
//

#include "MarketBook.h"

namespace API {
    MarketBook::MarketBook(Json::Value json) {
        marketId = json["marketId"].asString();
        isMarketDataDelayed = json["isMarketDataDelayed"].asBool();
        if (json.isMember("status"))
            status = json["status"].asString();
        if (json.isMember("betDelay"))
            betDelay = json["betDelay"].asInt();
        if (json.isMember("bspReconciled"))
            bspReconciled = json["bspReconciled"].asBool();
        if (json.isMember("complete"))
            complete = json["complete"].asBool();
        if (json.isMember("inplay"))
            inplay = json["inplay"].asBool();
        if (json.isMember("numberOfWinners"))
            numberOfWinners = json["numberOfWinners"].asInt();
        if (json.isMember("numberOfRunners"))
            numberOfRunners = json["numberOfRunners"].asInt();
        if (json.isMember("numberOfActiveRunners"))
            numberOfActiveRunners = json["numberOfActiveRunners"].asInt();
        if (json.isMember("lastMatchTime"))
            lastMatchTime = json["lastMatchTime"].asString();
        if (json.isMember("totalMatched"))
            totalMatched = json["totalMatched"].asDouble();
        if (json.isMember("totalAvailable"))
            totalAvailable = json["totalAvailable"].asDouble();
        if (json.isMember("crossMatching"))
            crossMatching = json["crossMatching"].asBool();
        if (json.isMember("runnersVoidable"))
            runnersVoidable = json["runnersVoidable"].asBool();
        if (json.isMember("version"))
            version = json["version"].asInt64();
        if (json.isMember("runners")) {
            const Json::Value result = json["runners"];
            std::vector<Runner> v;
            for (const auto &index : result) {
                v.emplace_back(Runner(index));
            }
            runners = v;
        }
        if (json.isMember("keyLineDescription"))
            keyLineDescription = KeyLineDescription(json["keyLineDescription"]);

    }
}