//
// Created by scott on 16/01/2020.
//

#include "BetfairMarket.h"

#include <utility>

BetfairMarket::BetfairMarket(std::string id, std::string exchange_id, std::string market_start_time,
                             std::string market_type, std::optional<int> number_of_winners, std::string name) :
                             BetfairObject(std::move(id)), m_exchange_id(std::move(exchange_id)), m_market_start_time(std::move(market_start_time)), m_market_type(std::move(market_type)), m_number_of_winners(std::move(number_of_winners)), m_name(std::move(name)) {

}

const std::string &BetfairMarket::get_name() const {
    return m_name;
}

const std::string &BetfairMarket::get_exchange_id() const {
    return m_exchange_id;
}

const std::string &BetfairMarket::get_market_start_time() const {
    return m_market_start_time;
}

const std::string &BetfairMarket::get_market_type() const {
    return m_market_type;
}

std::optional<int> BetfairMarket::get_number_of_winners() const {
    return m_number_of_winners;
}

Json::Value BetfairMarket::json() {
    Json::Value json;
    json["id"] = m_id;
    json["start_time"] = m_market_start_time;
    json["name"] = m_name;
    json["type"] = m_market_type;
    json["exchange_id"] = m_exchange_id;
    if (m_number_of_winners.has_value())
        json["number_of_winners"] = m_number_of_winners.value();
    if (m_persistenceEnabled.has_value())
        json["persistence_enabled"] = m_persistenceEnabled.value();
    if (m_bspMarket.has_value())
        json["bsp_market"] = m_bspMarket.value();
    if (m_suspendTime.has_value())
        json["m_suspendTime"] = m_suspendTime.value();
    if (m_settleTime.has_value())
        json["m_settleTime"] = m_settleTime.value();
    
    return json;
}

