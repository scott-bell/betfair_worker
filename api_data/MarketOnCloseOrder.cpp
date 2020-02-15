//
// Created by scott on 24/01/2020.
//

#include <jsoncpp/json/json.h>
#include "MarketOnCloseOrder.h"

namespace API {
    Json::Value MarketOnCloseOrder::json() const {
        Json::Value json;
        json["liability"] = liability;
        return json;
    }

    MarketOnCloseOrder::MarketOnCloseOrder(Json::Value json) {
        liability = json["liability"].asDouble();

    }
}

