//
// Created by scott on 21/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETFILTER_H
#define BETFAIR_WORKER_MARKETFILTER_H


#include <string>
#include <set>
#include <boost/property_tree/ptree.hpp>

struct MarketFilter {
    std::optional<std::set<std::string> > m_marketIds;
    std::optional<std::set<std::string> > m_withOrders;
    // TODO: lots more fields supported
public:
    explicit MarketFilter(const std::set<std::string>& marketIds);
    MarketFilter();
    boost::property_tree::ptree ptree();
};


#endif //BETFAIR_WORKER_MARKETFILTER_H
