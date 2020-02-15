//
// Created by scott on 26/01/2020.
//

#ifndef SXCLIENT_MARKETBOOK_H
#define SXCLIENT_MARKETBOOK_H

#include <string>
#include <optional>
#include <vector>
#include <jsoncpp/json/json.h>
#include "Runner.h"
#include "KeyLineDescription.h"

namespace API {
    struct MarketBook {
        std::string marketId;
        bool isMarketDataDelayed;
        std::optional<std::string> status;
        std::optional<int> betDelay;
        std::optional<bool> bspReconciled;
        std::optional<bool> complete;
        std::optional<bool> inplay;
        std::optional<int> numberOfWinners;
        std::optional<int> numberOfRunners;
        std::optional<int> numberOfActiveRunners;
        std::optional<std::string> lastMatchTime;
        std::optional<double> totalMatched;
        std::optional<double> totalAvailable;
        std::optional<bool> crossMatching;
        std::optional<bool> runnersVoidable;
        std::optional<long> version;
        std::optional<std::vector<Runner>> runners;
        std::optional<KeyLineDescription> keyLineDescription;

        explicit MarketBook(Json::Value json);

    };
}

#endif //SXCLIENT_MARKETBOOK_H
