//
// Created by scott on 23/01/2020.
//

#ifndef SXCLIENT_MARKETCATALOGUE_H
#define SXCLIENT_MARKETCATALOGUE_H

#include <string>
#include <vector>
#include "MarketDescription.h"
#include "RunnerCatalog.h"
#include "EventType.h"
#include "Competition.h"
#include "Event.h"

namespace API {

    struct MarketCatalogue {
        std::string marketId;
        std::string marketName;
        std::optional<std::string> marketStartTime;
        std::optional<MarketDescription> description;
        std::optional<double> totalMatched;
        std::optional<std::vector<RunnerCatalog> > runners;
        std::optional<EventType> eventType;
        std::optional<Competition> competition;
        std::optional<Event> event;

        explicit MarketCatalogue(Json::Value json);
    };
}

#endif //SXCLIENT_MARKETCATALOGUE_H
