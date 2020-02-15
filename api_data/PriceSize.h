//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_PRICESIZE_H
#define SXCLIENT_PRICESIZE_H


#include <jsoncpp/json/json.h>

namespace API {
    struct PriceSize {
        double price;
        double size;

        explicit PriceSize(Json::Value json);
    };
}

#endif //SXCLIENT_PRICESIZE_H
