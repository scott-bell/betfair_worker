//
// Created by scott on 26/01/2020.
//

#ifndef BETFAIR_WORKER_EXBESTOFFERSOVERRIDES_H
#define BETFAIR_WORKER_EXBESTOFFERSOVERRIDES_H


#include <string>
#include <boost/property_tree/ptree.hpp>

struct ExBestOffersOverrides {
    std::optional<int> bestPricesDepth;
    std::optional<std::string> rollupModel;
    std::optional<int> rollupLimit;
    std::optional<double> rollupLiabilityThreshold;
    std::optional<int> rollupLiabilityFactor;

    [[nodiscard]] boost::property_tree::ptree ptree() const;

};


#endif //BETFAIR_WORKER_EXBESTOFFERSOVERRIDES_H
