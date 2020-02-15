//
// Created by scott on 26/01/2020.
//

#ifndef SXCLIENT_EXBESTOFFERSOVERRIDES_H
#define SXCLIENT_EXBESTOFFERSOVERRIDES_H


#include <string>
#include <jsoncpp/json/json.h>

namespace API {
    struct ExBestOffersOverrides {
        std::optional<int> bestPricesDepth;
        std::optional<std::string> rollupModel;
        std::optional<int> rollupLimit;
        std::optional<double> rollupLiabilityThreshold;
        std::optional<int> rollupLiabilityFactor;

        [[nodiscard]] Json::Value json() const;

    };
}

#endif //SXCLIENT_EXBESTOFFERSOVERRIDES_H
