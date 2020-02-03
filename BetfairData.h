//
// Created by scott on 17/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRDATA_H
#define BETFAIR_WORKER_BETFAIRDATA_H

#include <vector>
#include <betfair_data/BetfairMarket.h>
#include <betfair_data/BetfairEventType.h>
#include <betfair_data/BetfairRace.h>
#include <betfair_data/BetfairGroup.h>
#include <betfair_data/BetfairEvent.h>
#include <unordered_map>
#include <betfair_data/BetfairRunner.h>

class BetfairData {
    bool m_verbose;
    std::unordered_map<std::string,BetfairMarket> m_betfairMarkets;
    std::unordered_map<std::string,BetfairEventType> m_betfairEventTypes;
    std::unordered_map<std::string,BetfairRace> m_betfairRace;
    std::unordered_map<std::string,BetfairGroup> m_betfairGroup;
    std::unordered_map<std::string,BetfairEvent> m_betfairEvent;
    std::unordered_map<std::string,BetfairRunner> m_betfairRunner;
public:
    BetfairData(): m_verbose(false) {
        m_betfairMarkets.reserve(30000);
        m_betfairEvent.reserve(5000);
        m_betfairRace.reserve(1000);
        m_betfairGroup.reserve(1000);
        m_betfairEventTypes.reserve(100);
        m_betfairRunner.reserve(100000);
    }
    BetfairEventType& addEventType(const std::string& id, std::string name);
    BetfairEvent& addEvent(const std::string &id, std::string name, std::string country_code);
    BetfairMarket& addMarket(const std::string &id, std::string exchange_id, std::string market_start_time, std::string market_type, int number_of_winners, std::string name);
    BetfairGroup& addGroup(const std::string &id, std::string name);
    BetfairRace& addRace(std::string id, std::string name, std::string start_time, std::string venue, std::string race_number, std::string country_code);
    BetfairRunner& addRunner(const std::string& id, std::string name);
    int displayEventType(const BetfairEventType& item) const;
    int displayEvent(const BetfairEvent* item) const;
    int displayGroup(const BetfairGroup* item) const;
    int displayRace(const BetfairRace* item) const;
    int displayMarket(const BetfairMarket* item) const;

    BetfairEventType* getBetfairEventType(const std::string& id);
    BetfairEvent* getBetfairEvent(const std::string& id);
    BetfairGroup* getBetfairGroup(const std::string& id);
    BetfairMarket* getBetfairMarket(const std::string& id);
    BetfairRace* getBetfairRace(const std::string& id);
    BetfairRunner* getBetfairRunner(const std::string& id);

    int nodeCountRecursive();
    unsigned long nodeCount() {
        return  m_betfairMarkets.size() +
                m_betfairEventTypes.size() +
                m_betfairRace.size() +
                m_betfairGroup.size() +
                m_betfairEvent.size();
    }

};


#endif //BETFAIR_WORKER_BETFAIRDATA_H
