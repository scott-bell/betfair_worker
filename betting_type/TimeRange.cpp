//
// Created by scott on 28/01/2020.
//

#include "TimeRange.h"

Json::Value TimeRange::json() const {
    Json::Value json;
    if (from.has_value())
        json["from"] = from.value();
    if (to.has_value())
        json["to"] = to.value();
    return json;
}
