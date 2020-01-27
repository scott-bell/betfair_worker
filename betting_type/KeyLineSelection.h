//
// Created by scott on 26/01/2020.
//

#ifndef BETFAIR_WORKER_KEYLINESELECTION_H
#define BETFAIR_WORKER_KEYLINESELECTION_H

#include <optional>
#include <jsoncpp/json/json.h>

struct KeyLineSelection {
    std::optional<long> selectionId;
    std::optional<double> handicap;

    explicit KeyLineSelection(Json::Value json);

};


#endif //BETFAIR_WORKER_KEYLINESELECTION_H
