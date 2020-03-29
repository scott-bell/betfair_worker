//
// Created by scott on 16/01/2020.
//

#include "EventType.h"

#include <utility>
#include <iostream>
namespace Data {
    EventType::EventType(std::string id, std::string name) : DataObject(id), m_name(std::move(name)) {
    }

    Json::Value EventType::json() const {
        Json::Value json;
        json["id"] = m_id;
        json["name"] = m_name;
        return json;
    }

    void EventType::addChild(Event *item) {
        m_children_event.push_back(item);
    }

    void EventType::addChild(Group *item) {
        m_children_group.push_back(item);
    }

    void EventType::addChild(Race *item) {
        m_children_race.push_back(item);
    }

    const std::string &EventType::get_name() const {
        return m_name;
    }

    const std::vector<Event *> &EventType::getEvents() const {
        return m_children_event;
    }

    const std::vector<Group *> &EventType::getGroups() const {
        return m_children_group;
    }

    const std::vector<Race *> &EventType::getRaces() const {
        return m_children_race;
    }

}