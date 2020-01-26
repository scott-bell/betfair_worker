//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_EVENTTYPERESULT_H
#define BETFAIR_WORKER_EVENTTYPERESULT_H


#include <optional>
#include "EventType.h"

struct EventTypeResult {
    std::optional<EventType> eventType;
    std::optional<int> marketCount;

};


#endif //BETFAIR_WORKER_EVENTTYPERESULT_H
