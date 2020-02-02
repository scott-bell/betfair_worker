//
// Created by scott on 26/01/2020.
//

#include "PriceProjection.h"

Json::Value PriceProjection::json() const {
    Json::Value json;

    if (priceData.has_value())
    {
        Json::Value nested;
        for (const auto& s : priceData.value()) {
            nested.append(s);
        }
        json["priceData"]= nested;
    }
    if (exBestOffersOverrides.has_value())
        json["exBestOffersOverrides"] = exBestOffersOverrides.value().json();
    if (virtualise.has_value())
        json["virtualise"] = virtualise.value();
    if (rolloverStakes.has_value())
        json["rolloverStakes"] = rolloverStakes.value();


    return json;


}