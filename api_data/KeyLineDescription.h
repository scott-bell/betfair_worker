//
// Created by scott on 26/01/2020.
//

#ifndef SXCLIENT_KEYLINEDESCRIPTION_H
#define SXCLIENT_KEYLINEDESCRIPTION_H

#include <optional>
#include <vector>
#include <jsoncpp/json/json.h>
#include "KeyLineSelection.h"

namespace API {
    struct KeyLineDescription {
        std::vector<KeyLineSelection> keyLine;

        explicit KeyLineDescription(Json::Value json);

    };
}

#endif //SXCLIENT_KEYLINEDESCRIPTION_H
