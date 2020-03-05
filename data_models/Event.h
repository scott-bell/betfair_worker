//
// Created by scott on 16/01/2020.
//

#ifndef SXCLIENT_DATA_EVENT_H
#define SXCLIENT_DATA_EVENT_H


#include <string>
#include <vector>
#include <iostream>
#include "DataObject.h"
#include "Group.h"
#include "Market.h"

namespace Data {

    class Group;
    class Market;

    class Event : public DataObject {
        std::string m_name;
        std::string m_country_code;
        std::vector<Event *> m_children_event{};
        std::vector<Group *> m_children_group{};
        std::vector<Market *> m_children_market{};
    public:
        Event(std::string id, std::string name, std::string country_code);

        Json::Value json();

        Event() = delete;

        ~Event() {
            //std::cout << "Destroyed Event " << m_id << std::endl;
        }

        void addChild(Event *item);
        void addChild(Group *item);
        void addChild(Market *item);
        const std::string &get_name() const;
        const std::string &get_country_code() const;
        const std::vector<Event *> &getEvents() const;
        const std::vector<Group *> &getGroups() const;
        const std::vector<Market *> &getMarkets() const;
    };
    inline bool operator==(const Event& lhs, const Event& rhs){ return lhs.id() == rhs.id();  }
    inline bool operator!=(const Event& lhs, const Event& rhs){ return !(lhs == rhs); }

}
#endif //SXCLIENT_DATA_EVENT_H
