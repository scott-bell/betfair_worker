//
// Created by scott on 26/01/2020.
//

#include "ExBestOffersOverrides.h"

Json::Value ExBestOffersOverrides::json() const {
    Json::Value json;
    if (bestPricesDepth.has_value())
        json["bestPricesDepth"] = bestPricesDepth.value();
    if (rollupModel.has_value())
        json["rollupModel"] = rollupModel.value();
    if (rollupLimit.has_value())
        json["rollupLimit"] = rollupLimit.value();
    if (rollupLiabilityThreshold.has_value())
        json["rollupLiabilityThreshold"] = rollupLiabilityThreshold.value();
    if (rollupLiabilityFactor.has_value())
        json["rollupLiabilityFactor"] = rollupLiabilityFactor.value();
    return json;
}
