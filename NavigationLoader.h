//
// Created by scott on 17/01/2020.
//

#ifndef SXCLIENT_NAVIGATIONLOADER_H
#define SXCLIENT_NAVIGATIONLOADER_H

#include <3rd-party/SimpleWeb/client_https.hpp>
#include <chrono>
#include <data_models/Market.h>
#include <data_models/EventType.h>
#include <data_models/Race.h>
#include <data_models/Group.h>
#include <data_models/Event.h>
#include "DataModels.h"

using std::cout;
using std::endl;

class NavigationLoader {
    std::vector<Data::Market> m_markets;
    std::vector<Data::EventType> m_eventTypes;
    std::vector<Data::Race> m_race;
    std::vector<Data::Group> m_group;
    std::vector<Data::Event> m_event;
    DataModels& m_dataModels;
    bool verbose;
    void importRoot();
    void importEventType(const Data::EventType* temp);
    template <typename T>
    void importEvent(const Data::Event* temp, int indent, T* parent);
    template <typename T>
    void importGroup(const Data::Group* temp, int indent, T* parent);
    template <typename T>
    void importMarket(const Data::Market* temp, int indent, T* parent);
    template <typename T>
    void importRace(const Data::Race* temp, int indent, T* parent);
    void processJSONRoot(const Json::Value& json);
    void processJSONEventType(const Json::Value& json);
    template <typename T>
    void processJSONEvent(const Json::Value& json, T& parent);
    template <typename T>
    void processJSONGroup(const Json::Value& json, T& parent);
    template <typename T>
    void processJSONMarket(const Json::Value& json, T& parent);
    template <typename T>
    void processJSONRace(const Json::Value& json, T& parent);
public:
    explicit NavigationLoader(DataModels& dataModels);
    void init();
};


#endif //SXCLIENT_NAVIGATIONLOADER_H
