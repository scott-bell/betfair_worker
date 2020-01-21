//
// Created by scott on 16/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIREVENT_H
#define BETFAIR_WORKER_BETFAIREVENT_H


#include <string>
#include <vector>
#include <iostream>
#include "BetfairObject.h"
#include "BetfairGroup.h"
#include "BetfairMarket.h"

class BetfairGroup;

class BetfairEvent : public BetfairObject {
    std::string m_name;
    std::string m_country_code;
    std::vector<BetfairEvent*> m_children_event{};
    std::vector<BetfairGroup*> m_children_group{};
    std::vector<BetfairMarket*> m_children_market{};
public:
    BetfairEvent(std::string id, std::string name, std::string country_code);
    BetfairEvent() = delete;
    ~BetfairEvent() {
        //std::cout << "Destroyed BetfairEvent " << m_id << std::endl;
    }
    void addChild(BetfairEvent* item);
    void addChild(BetfairGroup* item);
    void addChild(BetfairMarket* item);
    const std::string& get_name() const;
    const std::string& get_country_code() const;
    const std::vector<BetfairEvent*>& getBetfairEvents() const;
    const std::vector<BetfairGroup*>& getBetfairGroups() const;
    const std::vector<BetfairMarket*>& getBetfairMarkets() const;
};


#endif //BETFAIR_WORKER_BETFAIREVENT_H
