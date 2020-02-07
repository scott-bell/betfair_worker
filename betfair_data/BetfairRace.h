//
// Created by scott on 16/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRRACE_H
#define BETFAIR_WORKER_BETFAIRRACE_H


#include <string>
#include <vector>
#include "BetfairObject.h"
#include "BetfairMarket.h"

class BetfairRace : public BetfairObject {
    std::string m_name;
    std::string m_start_time;
    std::string m_venue;
    std::string m_race_number;
    std::string m_country_code;
    std::vector<BetfairMarket*> m_children_market;
public:
    BetfairRace(std::string id, std::string name, std::string start_time,
                std::string venue, std::string race_number, std::string country_code);
    BetfairRace() = delete;
    Json::Value json();
    void addChild(BetfairMarket* item);
    const std::string& get_name() const;
    const std::string& get_start_time() const;
    const std::string& get_venue() const;
    const std::string& get_race_number() const;
    const std::string& get_country_code() const;
    const std::vector<BetfairMarket*>& getBetfairMarkets() const;

};


#endif //BETFAIR_WORKER_BETFAIRRACE_H
