//
// Created by scott on 17/01/2020.
//

#ifndef BETFAIR_WORKER_NAVIGATIONLOADER_H
#define BETFAIR_WORKER_NAVIGATIONLOADER_H

#include <3rd-party/SimpleWeb/client_https.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <chrono>
#include <betfair_data/BetfairMarket.h>
#include <betfair_data/BetfairEventType.h>
#include <betfair_data/BetfairRace.h>
#include <betfair_data/BetfairGroup.h>
#include <betfair_data/BetfairEvent.h>
#include "BetfairData.h"

using std::cout;
using std::endl;

class NavigationLoader {
    std::vector<BetfairMarket> m_betfairMarkets;
    std::vector<BetfairEventType> m_betfairEventTypes;
    std::vector<BetfairRace> m_betfairRace;
    std::vector<BetfairGroup> m_betfairGroup;
    std::vector<BetfairEvent> m_betfairEvent;
    BetfairData& m_betfair_data;
    bool verbose;
    void importRoot();
    void importEventType(const BetfairEventType& item);
    template <typename T>
    void importEvent(const BetfairEvent* item, int indent, T& parent);
    template <typename T>
    void importGroup(const BetfairGroup* item, int indent, T& parent);
    template <typename T>
    void importMarket(const BetfairMarket* item, int indent, T& parent);
    template <typename T>
    void importRace(const BetfairRace* item, int indent, T& parent);
    void processJSONRoot(const boost::property_tree::ptree& parseTree);
    void processJSONEventType(const boost::property_tree::ptree& parseTree);
    template <typename T>
    void processJSONEvent(const boost::property_tree::ptree& parseTree, T& parent);
    template <typename T>
    void processJSONGroup(const boost::property_tree::ptree& parseTree, T& parent);
    template <typename T>
    void processJSONMarket(const boost::property_tree::ptree& parseTree, T& parent);
    template <typename T>
    void processJSONRace(const boost::property_tree::ptree& parseTree, T& parent);
public:
    explicit NavigationLoader(BetfairData& betfair_data);
    void init();
};


#endif //BETFAIR_WORKER_NAVIGATIONLOADER_H
