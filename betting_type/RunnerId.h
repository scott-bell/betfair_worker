//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_RUNNERID_H
#define BETFAIR_WORKER_RUNNERID_H

#include <string>
#include <optional>

struct RunnerId {
    std::string marketId;
    std::string selectionId;
    std::optional<double> handicap;
};


#endif //BETFAIR_WORKER_RUNNERID_H
