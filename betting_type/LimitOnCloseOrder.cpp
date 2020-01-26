//
// Created by scott on 24/01/2020.
//

#include <boost/property_tree/ptree.hpp>
#include "LimitOnCloseOrder.h"

boost::property_tree::ptree LimitOnCloseOrder::ptree() const {
    boost::property_tree::ptree tree;
    tree.put("liability",liability);
    tree.put("price",price);
    return tree;
}

LimitOnCloseOrder::LimitOnCloseOrder(Json::Value json) {

    liability = json["liability"].asDouble();
    price = json["price"].asDouble();

}
