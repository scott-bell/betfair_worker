//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_EVENTRESULT_H
#define SXCLIENT_EVENTRESULT_H


#include "Event.h"
#include <optional>

namespace API{
        class EventResult {
            std::optional<Event> event;
            std::optional<int> marketCount;
        };
}

#endif //SXCLIENT_EVENTRESULT_H
