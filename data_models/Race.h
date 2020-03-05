//
// Created by scott on 16/01/2020.
//

#ifndef SXCLIENT_RACE_H
#define SXCLIENT_RACE_H


#include <string>
#include <vector>
#include "DataObject.h"
#include "Market.h"

namespace Data {

    class Market;

    class Race : public DataObject {
        std::string m_name;
        std::string m_start_time;
        std::string m_venue;
        std::string m_race_number;
        std::string m_country_code;
        std::vector<Market *> m_children_market;
    public:
        Race(std::string id, std::string name, std::string start_time,
             std::string venue, std::string race_number, std::string country_code);

        Race() = delete;

        Json::Value json();

        void addChild(Market *item);

        const std::string &get_name() const;

        const std::string &get_start_time() const;

        const std::string &get_venue() const;

        const std::string &get_race_number() const;

        const std::string &get_country_code() const;

        const std::vector<Market *> &getMarkets() const;

    };
    inline bool operator==(const Race& lhs, const Race& rhs){ return lhs.id() == rhs.id();  }
    inline bool operator!=(const Race& lhs, const Race& rhs){ return !(lhs == rhs); }
}

#endif //SXCLIENT_RACE_H
