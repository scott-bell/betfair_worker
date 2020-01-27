//
// Created by scott on 23/01/2020.
//

#ifndef BETFAIR_WORKER_RUNNERCATALOG_H
#define BETFAIR_WORKER_RUNNERCATALOG_H

#include <string>
#include <map>
#include <optional>
#include <jsoncpp/json/value.h>

struct RunnerCatalog {

    long selectionId;
    std::string runnerName;
    double handicap;
    int sortPriority;
    std::optional<std::map<std::string, std::string> > metadata;

    explicit RunnerCatalog(Json::Value json);

};


#endif //BETFAIR_WORKER_RUNNERCATALOG_H
