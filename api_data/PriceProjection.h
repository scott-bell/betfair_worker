//
// Created by scott on 26/01/2020.
//

#ifndef SXCLIENT_PRICEPROJECTION_H
#define SXCLIENT_PRICEPROJECTION_H

#include <vector>
#include <optional>
#include <string>
#include <jsoncpp/json/json.h>
#include "ExBestOffersOverrides.h"

namespace API {
    struct PriceProjection {
        std::optional<std::vector<std::string> > priceData;
        std::optional<ExBestOffersOverrides> exBestOffersOverrides;
        std::optional<bool> virtualise;
        std::optional<bool> rolloverStakes;

        [[nodiscard]] Json::Value json() const;


    };
}
#endif //SXCLIENT_PRICEPROJECTION_H
