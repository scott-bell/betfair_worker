//
// Created by scott on 23/01/2020.
//

#include "RunnerCatalog.h"

namespace API {

    RunnerCatalog::RunnerCatalog(Json::Value json) {
        selectionId = json["selectionId"].asInt64();
        runnerName = json["runnerName"].asString();
        handicap = json["handicap"].asDouble();
        sortPriority = json["sortPriority"].asInt();
        // TODO: metadata
    }
}