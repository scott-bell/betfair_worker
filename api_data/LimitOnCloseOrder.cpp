//
// Created by scott on 24/01/2020.
//

#include "LimitOnCloseOrder.h"

namespace API {
    Json::Value LimitOnCloseOrder::json() const {
        Json::Value json;
        json["liability"] = liability;
        json["price"] = price;
        return json;
    }

    LimitOnCloseOrder::LimitOnCloseOrder(Json::Value json) {
        liability = json["liability"].asDouble();
        price = json["price"].asDouble();
    }
}
