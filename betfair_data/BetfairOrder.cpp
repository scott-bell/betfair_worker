//
// Created by scott on 07/02/2020.
//

#include "BetfairOrder.h"

#include <utility>

Json::Value BetfairOrder::json() {
    Json::Value json;
    json["id"] = m_id;
    json["market_id"] = m_market->get_id();
    json["runner_id"] = m_runner->get_id();
    json["handicap"] = m_handicap;
    json["price"] = m_price;
    json["size"] = m_size;
    json["bsp_liability"] = m_bspLiability;
    json["side"] = m_side;
    json["status"] = m_status;
    json["persistence_type"] = m_persistenceType;
    json["order_type"] = m_orderType;
    json["placed_date"] = m_placedDate;
    json["matched_date"] = m_matchedDate;
    json["size_matched"] = m_sizeMatched;
    json["size_remaining"] = m_sizeRemaining;
    json["size_lapsed"] = m_sizeLapsed;
    json["size_cancelled"] = m_sizeCancelled;
    json["size_voided"] = m_sizeVoided;
    if (m_regulatorAuthCode.has_value())
        json["regulator_auth_code"] = m_regulatorAuthCode.value();
    if (m_regulatorCode.has_value())
        json["regulator_code"] = m_regulatorCode.value();
    if (m_customerOrderRef.has_value())
        json["customer_order_ref"] = m_customerOrderRef.value();
    if (m_customerStrategyRef.has_value())
        json["customer_strategy_ref"] = m_customerStrategyRef.value();
    return json;
}

BetfairOrder::BetfairOrder(std::string id, BetfairMarket* market, BetfairRunner* runner, double handicap, double price,
                           double size, double bspLiability, std::string side, std::string status,
                           std::string persistenceType, std::string orderType, std::string placedDate,
                           std::string matchedDate, double sizeMatched, double sizeRemaining, double sizeLaped,
                           double sizeCancelled, double sizeVoided, std::optional<std::string> regulatorAuthCode,
                           std::optional<std::string> regulatorCode, std::optional<std::string> customOrderRef,
                           std::optional<std::string> customerStrategyRef)  :
        BetfairObject(std::move(id)), m_market(market), m_runner(runner), m_handicap(handicap), m_price(price), m_size(size),
        m_bspLiability(bspLiability), m_side(std::move(side)), m_status(std::move(status)), m_persistenceType(std::move(persistenceType)), m_orderType(std::move(std::move(orderType))),
        m_placedDate(std::move(placedDate)), m_matchedDate(std::move(matchedDate)), m_sizeMatched(sizeMatched), m_sizeRemaining(sizeRemaining),
        m_sizeLapsed(sizeLaped), m_sizeCancelled(sizeCancelled), m_sizeVoided(sizeVoided), m_regulatorAuthCode(std::move(regulatorAuthCode)),
        m_regulatorCode(std::move(regulatorCode)), m_customerOrderRef(std::move(customOrderRef)), m_customerStrategyRef(std::move(customerStrategyRef))

{

}

void BetfairOrder::status(std::string status) {
    m_status = status;
}

void BetfairOrder::sizeRemaining(double size) {
    m_sizeRemaining = size;
}
void BetfairOrder::sizeCancelled(double size) {
    m_sizeCancelled = size;
}

void BetfairOrder::persistenceType(std::string s) {
    m_persistenceType = s;
}

void BetfairOrder::sizeMatched(double size) {
    m_sizeMatched = size;
}
void BetfairOrder::sizeLapsed(double size) {
    m_sizeLapsed = size;
}

void BetfairOrder::sizeVoided(double size) {
    m_sizeVoided = size;
}
