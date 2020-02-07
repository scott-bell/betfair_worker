//
// Created by scott on 16/01/2020.
//

#include "BetfairEvent.h"

BetfairEvent::BetfairEvent(std::string id, std::string name, std::string country_code) : BetfairObject(id), m_name(name), m_country_code(country_code) {
    //std::cout << "BetfairEvent " << id << std::endl;
}

void BetfairEvent::addChild(BetfairEvent* item) {
    m_children_event.push_back(item);
}

void BetfairEvent::addChild(BetfairGroup* item) {
    m_children_group.push_back(item);
}

void BetfairEvent::addChild(BetfairMarket* item) {
    m_children_market.push_back(item);
}

const std::string &BetfairEvent::get_name() const {
    return m_name;
}

const std::vector<BetfairEvent*>& BetfairEvent::getBetfairEvents() const {
    return m_children_event;
}

const std::vector<BetfairGroup*>& BetfairEvent::getBetfairGroups() const {
    return m_children_group;
}

const std::vector<BetfairMarket*>& BetfairEvent::getBetfairMarkets() const {
    return m_children_market;
}

const std::string &BetfairEvent::get_country_code() const {
    return m_country_code;
}

Json::Value BetfairEvent::json() {
    Json::Value json;
    json["id"] = m_id;
    json["name"] = m_name;
    json["country_code"] = m_country_code;
    return json;
}

