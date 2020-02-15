//
// Created by scott on 16/01/2020.
//

#include "Event.h"

#include <utility>

namespace Data {

    Event::Event(std::string id, std::string name, std::string country_code) : DataObject(std::move(id)),
                                                                               m_name(std::move(name)),
                                                                               m_country_code(
                                                                                                     std::move(country_code)) {
    }

    void Event::addChild(Event *item) {
        m_children_event.push_back(item);
    }

    void Event::addChild(Group *item) {
        m_children_group.push_back(item);
    }

    void Event::addChild(Market *item) {
        m_children_market.push_back(item);
    }

    const std::string &Event::get_name() const {
        return m_name;
    }

    const std::vector<Event *> &Event::getEvents() const {
        return m_children_event;
    }

    const std::vector<Group *> &Event::getGroups() const {
        return m_children_group;
    }

    const std::vector<Market *> &Event::getMarkets() const {
        return m_children_market;
    }

    const std::string &Event::get_country_code() const {
        return m_country_code;
    }

    Json::Value Event::json() {
        Json::Value json;
        json["id"] = m_id;
        json["name"] = m_name;
        json["country_code"] = m_country_code;
        return json;
    }

}