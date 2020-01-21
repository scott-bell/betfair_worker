//
// Created by scott on 16/01/2020.
//

#include "BetfairRace.h"

#include <utility>

BetfairRace::BetfairRace(std::string id, std::string name, std::string start_time,
                         std::string venue, std::string race_number, std::string country_code) :
                         BetfairObject(std::move(id)), m_name(std::move(name)), m_start_time(std::move(start_time)), m_venue(std::move(venue)),
                         m_race_number(std::move(race_number)), m_country_code(std::move(country_code)) {

}

void BetfairRace::addChild(BetfairMarket* item) {
    m_children_market.push_back(item);
}

const std::string &BetfairRace::get_name() const {
    return m_name;
}

const std::vector<BetfairMarket*>& BetfairRace::getBetfairMarkets() const {
    return m_children_market;
}

const std::string &BetfairRace::get_start_time() const {
    return m_start_time;
}

const std::string &BetfairRace::get_venue() const {
    return m_venue;
}

const std::string &BetfairRace::get_race_number() const {
    return m_race_number;
}

const std::string &BetfairRace::get_country_code() const {
    return m_country_code;
}
