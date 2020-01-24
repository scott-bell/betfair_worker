//
// Created by scott on 21/01/2020.
//

#include "MarketFilter.h"


boost::property_tree::ptree MarketFilter::setToPtree(std::set<std::string> items) const
{
    using boost::property_tree::ptree;
    ptree tree;
    for (auto s : items) {
        ptree child;
        child.put("", s);
        tree.push_back(std::make_pair("", child));
    }
    return tree;
}

boost::property_tree::ptree MarketFilter::ptree() const {

    using boost::property_tree::ptree;
    ptree tree;


    if (m_eventTypeIds.has_value())
        tree.add_child("eventTypeIds", setToPtree(m_eventTypeIds.value()));
    if (m_eventIds.has_value())
        tree.add_child("eventIds", setToPtree(m_eventIds.value()));
    if (m_competitionIds.has_value())
        tree.add_child("competitionIds", setToPtree(m_competitionIds.value()));
    if (m_marketIds.has_value())
        tree.add_child("marketIds", setToPtree(m_marketIds.value()));
    if (m_venues.has_value())
        tree.add_child("venues", setToPtree(m_venues.value()));
    if (m_bspOnly.has_value())
        tree.put("bspOnly", m_bspOnly.value());
    if (m_turnInPlayEnabled.has_value())
        tree.put("turnInPlayEnabled", m_turnInPlayEnabled.value());
    if (m_inPlayOnly.has_value())
        tree.put("inPlayOnly", m_inPlayOnly.value());
    if (m_marketBettingTypes.has_value())
        tree.add_child("marketBettingTypes", setToPtree(m_marketBettingTypes.value()));
    if (m_marketCountries.has_value())
        tree.add_child("marketCountries", setToPtree(m_marketCountries.value()));
    if (m_marketTypeCodes.has_value())
        tree.add_child("marketTypeCodes", setToPtree(m_marketTypeCodes.value()));
    if (m_withOrders.has_value())
        tree.add_child("withOrders", setToPtree(m_withOrders.value()));
    if (m_raceTypes.has_value())
        tree.add_child("raceTypes", setToPtree(m_raceTypes.value()));


    return tree;

}

MarketFilter::MarketFilter(const std::set<std::string>& marketIds): m_marketIds(marketIds) {

}

MarketFilter::MarketFilter() {

}

