//
// Created by scott on 24/01/2020.
//

#include "PriceSize.h"

namespace API {

    PriceSize::PriceSize(Json::Value json) {
        price = json["price"].asDouble();
        size = json["size"].asDouble();

    }
}