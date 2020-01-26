//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_EVENTRESULT_H
#define BETFAIR_WORKER_EVENTRESULT_H


#include "Event.h"
#include <optional>

class EventResult {
    std::optional<Event> event;
    std::optional<int> marketCount;
};


#endif //BETFAIR_WORKER_EVENTRESULT_H
