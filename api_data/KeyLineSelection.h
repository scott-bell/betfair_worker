//
// Created by scott on 26/01/2020.
//

#ifndef SXCLIENT_KEYLINESELECTION_H
#define SXCLIENT_KEYLINESELECTION_H

#include <optional>
#include <jsoncpp/json/json.h>

namespace API {
    struct KeyLineSelection {
        std::optional<long> selectionId;
        std::optional<double> handicap;

        explicit KeyLineSelection(Json::Value json);

    };
}

#endif //SXCLIENT_KEYLINESELECTION_H
