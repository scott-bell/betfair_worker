//
// Created by scott on 16/01/2020.
//

#ifndef SXCLIENT_DATA_EVENTTYPE_H
#define SXCLIENT_DATA_EVENTTYPE_H


#include <string>
#include <vector>
#include <iostream>
#include "DataObject.h"
#include "Event.h"
#include "Group.h"
#include "Race.h"

namespace Data {

    class EventType : public DataObject {
        std::string m_name;
        std::vector<Event *> m_children_event;
        std::vector<Group *> m_children_group;
        std::vector<Race *> m_children_race;
    public:
        const std::string &get_name() const;

        Json::Value json() const;

        EventType(std::string id, std::string name);

        EventType() = delete;

        void addChild(Event *item);
        void addChild(Group *item);
        void addChild(Race *item);
        const std::vector<Event *> &getEvents() const;
        const std::vector<Group *> &getGroups() const;
        const std::vector<Race *> &getRaces() const;
    };

}
#endif //SXCLIENT_DATA_EVENTTYPE_H
