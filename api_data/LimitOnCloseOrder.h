//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_LIMITONCLOSEORDER_H
#define SXCLIENT_LIMITONCLOSEORDER_H


#include <jsoncpp/json/json.h>

namespace API {
    struct LimitOnCloseOrder {
        double liability;
        double price;

        [[nodiscard]] Json::Value json() const;

        explicit LimitOnCloseOrder(Json::Value json);
    };
}

#endif //SXCLIENT_LIMITONCLOSEORDER_H
