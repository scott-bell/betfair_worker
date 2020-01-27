//
// Created by scott on 26/01/2020.
//

#include "ExBestOffersOverrides.h"

boost::property_tree::ptree ExBestOffersOverrides::ptree() const {
    boost::property_tree::ptree tree;


    if (bestPricesDepth.has_value())
        tree.put("bestPricesDepth",bestPricesDepth.value());
    if (rollupModel.has_value())
        tree.put("rollupModel",rollupModel.value());
    if (rollupLimit.has_value())
        tree.put("rollupLimit",rollupLimit.value());
    if (rollupLiabilityThreshold.has_value())
        tree.put("rollupLiabilityThreshold",rollupLiabilityThreshold.value());
    if (rollupLiabilityFactor.has_value())
        tree.put("rollupLiabilityFactor",rollupLiabilityFactor.value());

    return tree;
}
