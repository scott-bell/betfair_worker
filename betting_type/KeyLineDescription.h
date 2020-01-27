//
// Created by scott on 26/01/2020.
//

#ifndef BETFAIR_WORKER_KEYLINEDESCRIPTION_H
#define BETFAIR_WORKER_KEYLINEDESCRIPTION_H

#include <optional>
#include <vector>
#include <jsoncpp/json/json.h>
#include "KeyLineSelection.h"

struct KeyLineDescription {
    std::vector<KeyLineSelection> keyLine;
    explicit KeyLineDescription(Json::Value json);

};


#endif //BETFAIR_WORKER_KEYLINEDESCRIPTION_H
