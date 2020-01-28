//
// Created by scott on 28/01/2020.
//

#include "TimeRange.h"

boost::property_tree::ptree TimeRange::ptree() const {
    boost::property_tree::ptree tree;
    if (from.has_value())
        tree.put("from", from.value());
    if (to.has_value())
        tree.put("to", to.value());
    return tree;
}