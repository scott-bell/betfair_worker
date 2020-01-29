//
// Created by scott on 24/01/2020.
//

#include "MarketVersion.h"

boost::property_tree::ptree MarketVersion::ptree() const {
    boost::property_tree::ptree tree;

    tree.put("version",version);

    return tree;
}
