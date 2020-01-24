//
// Created by scott on 21/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETFILTER_H
#define BETFAIR_WORKER_MARKETFILTER_H


#include <string>
#include <set>
#include <boost/property_tree/ptree.hpp>

struct MarketFilter {
    std::optional<std::string> m_textQuery;

    std::optional<std::set<std::string> > m_eventTypeIds;
    std::optional<std::set<std::string> > m_eventIds;
    std::optional<std::set<std::string> > m_competitionIds;
    std::optional<std::set<std::string> > m_marketIds;
    std::optional<std::set<std::string> > m_venues;
    std::optional<bool> m_bspOnly;
    std::optional<bool> m_turnInPlayEnabled;
    std::optional<bool> m_inPlayOnly;
    std::optional<std::set<std::string> > m_marketBettingTypes;
    std::optional<std::set<std::string> > m_marketCountries;
    std::optional<std::set<std::string> > m_marketTypeCodes;
    std::optional<std::set<std::string> > m_withOrders;
    std::optional<std::set<std::string> > m_raceTypes;
    // TODO: lots more fields supported
    boost::property_tree::ptree setToPtree(std::set<std::string>) const;
public:
    explicit MarketFilter(const std::set<std::string>& marketIds);
    MarketFilter();

    boost::property_tree::ptree ptree() const;
};


#endif //BETFAIR_WORKER_MARKETFILTER_H
