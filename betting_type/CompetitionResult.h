//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_COMPETITIONRESULT_H
#define BETFAIR_WORKER_COMPETITIONRESULT_H


#include "Competition.h"
#include <optional>

class CompetitionResult {
    std::optional<Competition> competition;
    std::optional<int> marketCount;
    std::optional<std::string> competitionRegion;

};


#endif //BETFAIR_WORKER_COMPETITIONRESULT_H
