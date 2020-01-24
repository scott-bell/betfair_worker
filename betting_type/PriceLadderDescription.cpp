//
// Created by scott on 23/01/2020.
//

#include "PriceLadderDescription.h"

PriceLadderDescription::PriceLadderDescription(Json::Value json) {
    if (json.isMember("type"))
        type = json["type"].asString();
}
