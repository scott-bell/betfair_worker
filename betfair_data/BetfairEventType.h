//
// Created by scott on 16/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIREVENTTYPE_H
#define BETFAIR_WORKER_BETFAIREVENTTYPE_H


#include <string>
#include <vector>
#include <iostream>
#include "BetfairObject.h"
#include "BetfairEvent.h"
#include "BetfairGroup.h"
#include "BetfairRace.h"

class BetfairEventType : public BetfairObject {
    std::string m_name;
    std::vector<BetfairEvent*> m_children_event;
    std::vector<BetfairGroup*> m_children_group;
    std::vector<BetfairRace*> m_children_race;
public:
    const std::string& get_name() const;
    Json::Value json();
    BetfairEventType(std::string id, std::string name);
    BetfairEventType() = delete;
    void addChild(BetfairEvent* item);
    void addChild(BetfairGroup* item);
    void addChild(BetfairRace* item);
    const std::vector<BetfairEvent*>& getBetfairEvents() const;
    const std::vector<BetfairGroup*>& getBetfairGroups() const;
    const std::vector<BetfairRace*>& getBetfairRaces() const;
};


#endif //BETFAIR_WORKER_BETFAIREVENTTYPE_H
