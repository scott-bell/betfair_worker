//
// Created by scott on 28/01/2020.
//

#ifndef BETFAIR_WORKER_TIMERANGE_H
#define BETFAIR_WORKER_TIMERANGE_H

#include <optional>
#include <string>
#include <jsoncpp/json/json.h>

struct TimeRange {
    std::optional<std::string> from;
    std::optional<std::string> to;
    [[nodiscard]] Json::Value json() const;
};


#endif //BETFAIR_WORKER_TIMERANGE_H
