//
// Created by scott on 16/01/2020.
//

#ifndef SXCLIENT_GROUP_H
#define SXCLIENT_GROUP_H

#include <string>
#include <vector>
#include "Event.h"
#include "Group.h"
#include <jsoncpp/json/json.h>

namespace Data {
    class Event;

    class Group : public DataObject {
        std::string m_name;
        std::vector<Event *> m_children_event;
        std::vector<Group *> m_children_group;
    public:
        Group(std::string id, std::string name);

        Group() = delete;

        Json::Value json() const;
        void addChild(Event *item);
        void addChild(Group *item);
        const std::string &get_name() const;
        const std::vector<Event *> &getEvents() const;
        const std::vector<Group *> &getGroups() const;
    };

}
#endif //SXCLIENT_GROUP_H
