//
// Created by scott on 16/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRGROUP_H
#define BETFAIR_WORKER_BETFAIRGROUP_H

#include <string>
#include <vector>
#include "BetfairEvent.h"
#include "BetfairGroup.h"
#include <jsoncpp/json/json.h>


class BetfairEvent;

class BetfairGroup : public BetfairObject {
    std::string m_name;
    std::vector<BetfairEvent*> m_children_event;
    std::vector<BetfairGroup*> m_children_group;
public:
    BetfairGroup(std::string id, std::string name);
    BetfairGroup() = delete;
    Json::Value json();
    void addChild(BetfairEvent* item);
    void addChild(BetfairGroup* item);
    const std::string& get_name() const;
    const std::vector<BetfairEvent*>& getBetfairEvents() const;
    const std::vector<BetfairGroup*>& getBetfairGroups() const;
};


#endif //BETFAIR_WORKER_BETFAIRGROUP_H
