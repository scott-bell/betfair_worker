//
// Created by scott on 17/01/2020.
//

#include "BetfairData.h"
#include <utility>

BetfairEventType& BetfairData::addEventType(const BetfairEventType& t) {
    auto item = m_betfairEventTypes.emplace(t.get_id(), t);
    return item.first->second;
}

BetfairEvent& BetfairData::addEvent(const BetfairEvent& t) {
    auto item = m_betfairEvent.emplace(t.get_id(), t);
    return item.first->second;
}

BetfairGroup &BetfairData::addGroup(const BetfairGroup& t) {
    auto item = m_betfairGroup.emplace(t.get_id(), t);
    return item.first->second;
}


BetfairMarket &BetfairData::addMarket(const BetfairMarket& t) {
    auto item = m_betfairMarkets.emplace(t.get_id(), t);
    return item.first->second;
}

BetfairRace &BetfairData::addRace(const BetfairRace& t) {
    auto item = m_betfairRace.emplace(t.get_id(), t);
    return item.first->second;
}

BetfairRunner &BetfairData::addRunner(const BetfairRunner& t) {
    auto item = m_betfairRunner.emplace(t.get_id(), t);
    return item.first->second;
}

BetfairRunner* BetfairData::getBetfairRunner(const std::string& id) {
    auto item = m_betfairRunner.find(id);
    if (item != m_betfairRunner.end())
        return &item->second;
    else
        return nullptr;
}
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

