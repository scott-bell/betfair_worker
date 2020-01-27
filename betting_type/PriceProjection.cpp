//
// Created by scott on 26/01/2020.
//

#include "PriceProjection.h"

boost::property_tree::ptree PriceProjection::ptree() const {
    boost::property_tree::ptree tree;

    if (priceData.has_value())
    {
        boost::property_tree::ptree ntree;
        for (const auto& s : priceData.value()) {
            boost::property_tree::ptree child;
            child.put("", s);
            ntree.push_back(std::make_pair("", child));
        }
        tree.put_child("priceData", ntree);
    }
    if (exBestOffersOverrides.has_value())
        tree.put_child("exBestOffersOverrides", exBestOffersOverrides.value().ptree());
    if (virtualise.has_value())
        tree.put("virtualise", virtualise.value());
    if (rolloverStakes.has_value())
        tree.put("rolloverStakes", rolloverStakes.value());


    return tree;
}
