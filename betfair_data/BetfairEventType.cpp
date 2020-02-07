//
// Created by scott on 16/01/2020.
//

#include "BetfairEventType.h"

#include <utility>
#include <iostream>

BetfairEventType::BetfairEventType(std::string id, std::string name) :  BetfairObject(id), m_name(std::move(name))
{
    //std::cout << "BetfairEventType " << id << std::endl;

}

Json::Value BetfairEventType::json() {
    Json::Value json;
    json["id"] = m_id;
    json["name"] = m_name;
    return json;
}

void BetfairEventType::addChild(BetfairEvent* item) {
    m_children_event.push_back(item);
}

void BetfairEventType::addChild(BetfairGroup* item) {
    m_children_group.push_back(item);
}

void BetfairEventType::addChild(BetfairRace* item) {
    m_children_race.push_back(item);
}

const std::string& BetfairEventType::get_name() const {
    return m_name;
}

const std::vector<BetfairEvent*>& BetfairEventType::getBetfairEvents() const {
    return m_children_event;
}

const std::vector<BetfairGroup*>& BetfairEventType::getBetfairGroups() const {
    return m_children_group;
}

const std::vector<BetfairRace*>& BetfairEventType::getBetfairRaces() const {
    return m_children_race;
}

