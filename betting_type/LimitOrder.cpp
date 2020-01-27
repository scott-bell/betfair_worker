//
// Created by scott on 24/01/2020.
//

#include <boost/property_tree/ptree.hpp>
#include <utility>
#include "LimitOrder.h"

boost::property_tree::ptree LimitOrder::ptree() const {

    boost::property_tree::ptree tree;

    tree.put("size",size);
    tree.put("price",price);
    tree.put("persistenceType",persistenceType);
    if (timeInForce.has_value())
        tree.put("timeInForce",timeInForce.value());
    if (minFillSize.has_value())
        tree.put("minFillSize",minFillSize.value());
    if (betTargetType.has_value())
        tree.put("betTargetType",betTargetType.value());
    if (betTargetSize.has_value())
        tree.put("betTargetSize",betTargetSize.value());


    return tree;

}

LimitOrder::LimitOrder(Json::Value json) {

    size = json["size"].asDouble();
    price = json["price"].asDouble();
    persistenceType = json["persistenceType"].asString();
    if (json.isMember("timeInForce"))
        timeInForce = json["timeInForce"].asString();
    if (json.isMember("minFillSize"))
        minFillSize = json["minFillSize"].asDouble();
    if (json.isMember("betTargetType"))
        betTargetType = json["betTargetType"].asString();
    if (json.isMember("betTargetSize"))
        betTargetSize = json["betTargetSize"].asDouble();

}

LimitOrder::LimitOrder(double size, double price, std::string persistenceType, std::optional<std::string> timeInForce,
                       std::optional<double> minFillSize, std::optional<std::string> betTargetType,
                       std::optional<double> betTargetSize) :
                       size(size), price(price), persistenceType(std::move(persistenceType)), timeInForce(std::move(timeInForce)), minFillSize(std::move(minFillSize)), betTargetType(std::move(betTargetType)), betTargetSize(std::move(betTargetSize))
{
}