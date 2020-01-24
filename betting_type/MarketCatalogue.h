//
// Created by scott on 23/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETCATALOGUE_H
#define BETFAIR_WORKER_MARKETCATALOGUE_H

#include <string>
#include <vector>
#include "betting_type/MarketDescription.h"
#include "RunnerCatalog.h"
#include "betting_type/EventType.h"
#include "betting_type/Competition.h"
#include "Event.h"

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


#endif //BETFAIR_WORKER_MARKETCATALOGUE_H
