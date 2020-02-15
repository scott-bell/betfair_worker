//
// Created by scott on 23/01/2020.
//

#ifndef SXCLIENT_PRICELADDERDESCRIPTION_H
#define SXCLIENT_PRICELADDERDESCRIPTION_H

#include <string>
#include <jsoncpp/json/value.h>

namespace API {
    struct PriceLadderDescription {
        std::string type;   // PriceLadderType enum


        explicit PriceLadderDescription(Json::Value json);
    };
}

#endif //SXCLIENT_PRICELADDERDESCRIPTION_H
