//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_RUNNERID_H
#define SXCLIENT_RUNNERID_H

#include <string>
#include <optional>

namespace API {
    struct RunnerId {
        std::string marketId;
        std::string selectionId;
        std::optional<double> handicap;
    };
}

#endif //SXCLIENT_RUNNERID_H
