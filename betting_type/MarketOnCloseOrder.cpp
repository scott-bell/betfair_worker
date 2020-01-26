//
// Created by scott on 24/01/2020.
//

#include <jsoncpp/json/json.h>
#include "MarketOnCloseOrder.h"

boost::property_tree::ptree MarketOnCloseOrder::ptree() const {
    boost::property_tree::ptree tree;
    tree.put("liability",liability);
    return tree;
}

MarketOnCloseOrder::MarketOnCloseOrder(Json::Value json) {
    liability = json["liability"].asDouble();

}
