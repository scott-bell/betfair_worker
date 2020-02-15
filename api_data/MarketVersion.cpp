//
// Created by scott on 24/01/2020.
//

#include "MarketVersion.h"

namespace API {
    Json::Value MarketVersion::json() const {
        Json::Value json;
        json["version"] = std::to_string(version);
        return json;
    }
}