//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_MARKETONCLOSEORDER_H
#define SXCLIENT_MARKETONCLOSEORDER_H

namespace API {
    struct MarketOnCloseOrder {
        double liability;

        [[nodiscard]] Json::Value json() const;

        explicit MarketOnCloseOrder(Json::Value json);

    };
}

#endif //SXCLIENT_MARKETONCLOSEORDER_H
