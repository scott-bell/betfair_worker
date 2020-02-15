//
// Created by scott on 26/01/2020.
//

#include "KeyLineDescription.h"

namespace API {
    KeyLineDescription::KeyLineDescription(Json::Value json) {
        if (json.isMember("keyLine")) {
            const Json::Value result = json["keyLine"];
            std::vector<KeyLineSelection> v;
            for (const auto &index : result) {
                v.emplace_back(KeyLineSelection(index));
            }
            keyLine = v;
        }

    }
}