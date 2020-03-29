//
// Created by scott on 16/01/2020.
//

#include "Race.h"

#include <utility>

namespace Data {

    Race::Race(std::string id, std::string name, std::string start_time,
               std::string venue, std::string race_number, std::string country_code) :
            DataObject(std::move(id)), m_name(std::move(name)), m_start_time(std::move(start_time)),
            m_venue(std::move(venue)),
            m_race_number(std::move(race_number)), m_country_code(std::move(country_code)) {

    }

    Json::Value Race::json() const {
        Json::Value json;
        json["id"] = m_id;
        json["name"] = m_name;
        json["start_time"] = m_start_time;
        json["venue"] = m_venue;
        json["race_number"] = m_race_number;
        json["country_code"] = m_country_code;
        return json;
    }


    void Race::addChild(Market *item) {
        m_children_market.push_back(item);
        item->parentRace(this);
    }

    const std::string &Race::get_name() const {
        return m_name;
    }

    const std::vector<Market *> &Race::getMarkets() const {
        return m_children_market;
    }

    const std::string &Race::get_start_time() const {
        return m_start_time;
    }

    const std::string &Race::get_venue() const {
        return m_venue;
    }

    const std::string &Race::get_race_number() const {
        return m_race_number;
    }

    const std::string &Race::get_country_code() const {
        return m_country_code;
    }
}