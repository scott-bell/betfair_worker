//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_EVENTTYPERESULT_H
#define SXCLIENT_EVENTTYPERESULT_H


#include <optional>
#include "EventType.h"

namespace API {
    struct EventTypeResult {
        std::optional<EventType> eventType;
        std::optional<int> marketCount;

    };
}

#endif //SXCLIENT_EVENTTYPERESULT_H
