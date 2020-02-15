//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_COMPETITIONRESULT_H
#define SXCLIENT_COMPETITIONRESULT_H


#include "Competition.h"
#include <optional>

namespace API {

    class CompetitionResult {
        std::optional<Competition> competition;
        std::optional<int> marketCount;
        std::optional<std::string> competitionRegion;

    };
}

#endif //SXCLIENT_COMPETITIONRESULT_H
