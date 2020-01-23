//
// Created by scott on 21/01/2020.
//

#include "MarketFilter.h"



boost::property_tree::ptree MarketFilter::ptree() {

    using boost::property_tree::ptree;
    ptree tree;


    if (m_marketIds.has_value()) {
        ptree marketIds;
        for (auto s : m_marketIds.value()) {
            ptree child;
            child.put("", s);
            marketIds.push_back(std::make_pair("", child));
        }
        tree.add_child("marketIds", marketIds);
    }
    if (m_withOrders.has_value()) {
        ptree subtree;
        for (auto s : m_withOrders.value()) {
            ptree child;
            child.put("", s);
            subtree.push_back(std::make_pair("", child));
        }
        tree.add_child("withOrders", subtree);
    }


    return tree;

}

MarketFilter::MarketFilter(const std::set<std::string>& marketIds): m_marketIds(marketIds) {

}

MarketFilter::MarketFilter() {

}
