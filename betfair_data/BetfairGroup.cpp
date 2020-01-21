#include "BetfairGroup.h"
#include <utility>

BetfairGroup::BetfairGroup(std::string id, std::string name) : BetfairObject(std::move(id)), m_name(std::move(name)) {

}

void BetfairGroup::addChild(BetfairEvent* item) {
    m_children_event.push_back(item);
}

void BetfairGroup::addChild(BetfairGroup* item) {
    m_children_group.push_back(item);
}

const std::string &BetfairGroup::get_name() const {
    return m_name;
}

const std::vector<BetfairEvent*>& BetfairGroup::getBetfairEvents() const {
    return m_children_event;
}

const std::vector<BetfairGroup*>& BetfairGroup::getBetfairGroups() const {
    return m_children_group;
}
