//
// Created by scott on 23/01/2020.
//

#ifndef SXCLIENT_RUNNERCATALOG_H
#define SXCLIENT_RUNNERCATALOG_H

#include <string>
#include <map>
#include <optional>
#include <jsoncpp/json/value.h>
namespace API {

    struct RunnerCatalog {

        long selectionId;
        std::string runnerName;
        double handicap;
        int sortPriority;
        std::optional<std::map<std::string, std::string> > metadata;

        explicit RunnerCatalog(Json::Value json);

    };
}

#endif //SXCLIENT_RUNNERCATALOG_H
