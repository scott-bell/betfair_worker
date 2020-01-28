//
// Created by scott on 28/01/2020.
//

#ifndef BETFAIR_WORKER_TIMERANGE_H
#define BETFAIR_WORKER_TIMERANGE_H

#include <optional>
#include <string>
#include <boost/property_tree/ptree.hpp>

struct TimeRange {
    std::optional<std::string> from;
    std::optional<std::string> to;
    [[nodiscard]] boost::property_tree::ptree ptree() const;
};


#endif //BETFAIR_WORKER_TIMERANGE_H
