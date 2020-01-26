//
// Created by scott on 24/01/2020.
//

#include "PlaceInstruction.h"

#include <utility>

boost::property_tree::ptree PlaceInstruction::ptree() const {
    using boost::property_tree::ptree;
    ptree tree;


    tree.put("orderType",orderType);
    tree.put("selectionId",selectionId);
    if (handicap.has_value())
        tree.put("handicap",handicap.value());
    tree.put("side",side);
    if (limitOrder.has_value())
        tree.put_child("limitOrder",limitOrder.value().ptree());
    if (limitOnCloseOrder.has_value())
        tree.put_child("limitOnCloseOrder",limitOnCloseOrder.value().ptree());
    if (marketOnCloseOrder.has_value())
        tree.put_child("marketOnCloseOrder",marketOnCloseOrder.value().ptree());
    if (customerOrderRef.has_value())
        tree.put("customerOrderRef",customerOrderRef.value());




    return tree;
}

PlaceInstruction::PlaceInstruction(Json::Value json) {
    orderType = json["orderType"].asString();
    selectionId = json["selectionId"].asInt();
    if (json.isMember("handicap"))
        handicap = json["handicap"].asDouble();
    side = json["side"].asString();
    if (json.isMember("limitOrder"))
        limitOrder = LimitOrder(json["limitOrder"]);
    if (json.isMember("limitOnCloseOrder"))
        limitOnCloseOrder = LimitOnCloseOrder(json["limitOnCloseOrder"]);
    if (json.isMember("marketOnCloseOrder"))
        marketOnCloseOrder = MarketOnCloseOrder(json["limitOrder"]);



}

PlaceInstruction::PlaceInstruction(std::string orderType, long selectionId, std::optional<double> handicap,
                                   std::string side, std::optional<LimitOrder> limitOrder,
                                   std::optional<LimitOnCloseOrder> limitOnCloseOrder,
                                   std::optional<MarketOnCloseOrder> marketOnCloseOrder,
                                   std::optional<std::string> customerOrderRef):
                                   orderType(std::move(orderType)), selectionId(selectionId), handicap(std::move(handicap)), side(std::move(side)), limitOrder(std::move(limitOrder)), limitOnCloseOrder(std::move(limitOnCloseOrder)), marketOnCloseOrder(std::move(marketOnCloseOrder)), customerOrderRef(std::move(customerOrderRef))
{

}

