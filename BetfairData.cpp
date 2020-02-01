//
// Created by scott on 17/01/2020.
//

#include "BetfairData.h"
#include <utility>

BetfairEventType& BetfairData::addEventType(const std::string& id, std::string name) {
    auto item = m_betfairEventTypes.emplace(id, BetfairEventType(id,std::move(name)));
    return item.first->second;
}

BetfairEvent& BetfairData::addEvent(const std::string &id, std::string name, std::string country_code) {
    auto item = m_betfairEvent.emplace(id, BetfairEvent(id,std::move(name),std::move(country_code)));
    return item.first->second;
}

BetfairGroup &BetfairData::addGroup(const std::string &id, std::string name) {
    auto item = m_betfairGroup.emplace(id, BetfairGroup(id,std::move(name)));
    return item.first->second;
}


BetfairMarket &BetfairData::addMarket(const std::string &id, std::string exchange_id, std::string market_start_time,
                                      std::string market_type, int number_of_winners, std::string name) {
    auto item = m_betfairMarkets.emplace(id, BetfairMarket(id,std::move(exchange_id), std::move(market_start_time), std::move(market_type), number_of_winners, name));
    return item.first->second;
}

BetfairRace &BetfairData::addRace(std::string id, std::string name, std::string start_time, std::string venue,
                                  std::string race_number, std::string country_code) {
    auto item = m_betfairRace.emplace(id, BetfairRace(id, std::move(name), std::move(start_time), std::move(venue), std::move(race_number), std::move(country_code)));
    return item.first->second;
}


// p_item = &(m_betfair_data.addEvent(parent, item.get_id(), item.get_name()));
/*template<typename T>
BetfairEvent& BetfairData::addEvent(const T& parent, const std::string& id, std::string name, std::string country_code) {
    auto item = m_betfairEvent.emplace(id, BetfairEvent(id,name,country_code));
    parent.addChild(item);
    return item.first->second;
}*/


BetfairEvent* BetfairData::getBetfairEvent(const std::string& id) {
    auto item = m_betfairEvent.find(id);
    if (item != m_betfairEvent.end())
        return &item->second;
    else
        return nullptr;
}
BetfairGroup* BetfairData::getBetfairGroup(const std::string& id) {
    auto item = m_betfairGroup.find(id);
    if (item != m_betfairGroup.end())
        return &item->second;
    else
        return nullptr;
}
BetfairMarket* BetfairData::getBetfairMarket(const std::string& id) {
    auto item = m_betfairMarkets.find(id);
    if (item != m_betfairMarkets.end())
        return &item->second;
    else
        return nullptr;
}
BetfairRace* BetfairData::getBetfairRace(const std::string& id) {
    auto item = m_betfairRace.find(id);
    if (item != m_betfairRace.end())
        return &item->second;
    else
        return nullptr;
}

BetfairEventType* BetfairData::getBetfairEventType(const std::string& id)  {
    auto item = m_betfairEventTypes.find(id);
    if (item != m_betfairEventTypes.end())
        return &item->second;
    else
        return nullptr;
}
int BetfairData::nodeCountRecursive() {
    int sum = 0;
    for (const auto& x : m_betfairEventTypes) {
        sum += displayEventType(x.second);
    }
    return sum;
}
int BetfairData::displayEventType(const BetfairEventType& item) const {
    if (m_verbose)
        std::cout << '[' << item.get_name() << ' ' << item.get_id() << std::endl;
    int sum = 1;
    for (const BetfairEvent* x : item.getBetfairEvents()) {
        sum += displayEvent(x);
    }
    for (const BetfairGroup* x : item.getBetfairGroups()) {
        sum += displayGroup(x);
    }
    for (const BetfairRace* x : item.getBetfairRaces()) {
        sum += displayRace(x);
    }
    return sum;
}
int BetfairData::displayEvent(const BetfairEvent* item) const {
    if (m_verbose)
        std::cout << '(' << item->get_name() << ' ' << item->get_id() << std::endl;
    int sum = 1;
    for (const BetfairEvent* x : item->getBetfairEvents()) {
        sum += displayEvent(x);
    }
    for (const BetfairGroup* x : item->getBetfairGroups()) {
        sum += displayGroup(x);
    }
    for (const BetfairMarket* x : item->getBetfairMarkets()) {
        sum += displayMarket(x);
    }
    return sum;
}

int BetfairData::displayGroup(const BetfairGroup* item) const {
    if (m_verbose)
        std::cout << '{' << item->get_name() << ' ' << item->get_id() << std::endl;
    int sum = 1;
    for (const BetfairEvent* x : item->getBetfairEvents()) {
        sum += displayEvent(x);
    }
    for (const BetfairGroup* x : item->getBetfairGroups()) {
        sum += displayGroup(x);
    }
    return sum;
}
int BetfairData::displayMarket(const BetfairMarket* item) const {
    if (m_verbose)
        std::cout << '<' << item->name() << ' ' << item->get_id() << std::endl;
    return 1;
}
int BetfairData::displayRace(const BetfairRace* item) const {
    if (m_verbose)
        std::cout << '!' << item->get_name() << ' ' << item->get_id() << std::endl;
    int sum = 1;
    for (const BetfairMarket* x : item->getBetfairMarkets()) {
        sum += displayMarket(x);
    }
    return sum;
}