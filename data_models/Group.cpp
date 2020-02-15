#include "Group.h"
#include <utility>

namespace Data {

    Group::Group(std::string id, std::string name) : DataObject(std::move(id)),
                                                     m_name(std::move(name)) {

    }

    Json::Value Group::json() {
        Json::Value json;
        json["id"] = m_id;
        json["name"] = m_name;
        return json;
    }

    void Group::addChild(Event *item) {
        m_children_event.push_back(item);
    }

    void Group::addChild(Group *item) {
        m_children_group.push_back(item);
    }

    const std::string &Group::get_name() const {
        return m_name;
    }

    const std::vector<Event *> &Group::getEvents() const {
        return m_children_event;
    }

    const std::vector<Group *> &Group::getGroups() const {
        return m_children_group;
    }
}