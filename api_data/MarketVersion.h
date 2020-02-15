//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_MARKETVERSION_H
#define SXCLIENT_MARKETVERSION_H

#include <optional>
#include <jsoncpp/json/json.h>

namespace API {
    struct MarketVersion {
        long version;

        [[nodiscard]] Json::Value json() const;
    };
}

#endif //SXCLIENT_MARKETVERSION_H
