//
// Created by scott on 17/01/2020.
//

#include "NavigationLoader.h"
#include "Authentication.h"

using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;


void NavigationLoader::init() {
    m_markets.reserve(30000);
    m_event.reserve(5000);
    m_race.reserve(1000);
    m_group.reserve(1000);
    m_eventTypes.reserve(100);

    HttpsClient client("api.betfair.com:443", true);

    SimpleWeb::CaseInsensitiveMultimap header;
    header.emplace("Accept", "application/json");
    header.emplace("Content-type", "application/json");
    header.emplace("X-Application", Authentication::applicationId);
    header.emplace("X-Authentication", Authentication::token);

    client.request(
            "POST",
            "/exchange/betting/rest/v1/en/navigation/menu.json",
            "",
            header,
            [&](std::shared_ptr<HttpsClient::Response> response,
               const SimpleWeb::error_code &ec)
            {
                if(!ec)
                {
                    Json::Value json;
                    {
                        auto t1 = std::chrono::high_resolution_clock::now();
                        std::cout << "Parsing JSON structure ... " << response->content.size() << " bytes" << std::endl;
                        response->content >> json;
                        auto t2 = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
                        std::cout << "Parsed JSON in " << duration << std::endl;
                    }
                    {
                        auto t1 = std::chrono::high_resolution_clock::now();
                        std::string type = json["type"].asString();
                        std::string name = json["name"].asString();
                        std::cout << "Recursing through json..." << std::endl;
                        processJSONRoot(json);
                        std::cout << "Done." << std::endl;
                        auto t2 = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
                        unsigned long node_count = m_markets.size() + m_event.size() + m_race.size() + m_group.size() + m_eventTypes.size();
                        std::cout << "Parsed JSON in " << duration << ". "
                                        "Markets: " << m_markets.size() <<
                                  ", events: " << m_event.size() <<
                                  ", races: " << m_race.size() <<
                                  ", groups: " << m_group.size() <<
                                  ", event types: " << m_eventTypes.size() <<
                                  ", total: " << node_count <<
                                  std::endl;
                    }
                }
            });
    client.io_service->run();
    importRoot();
}

void NavigationLoader::importRoot() {
    for (const Data::EventType& item : m_eventTypes) {
        importEventType(&item);
    }
}

void NavigationLoader::importEventType(const Data::EventType* temp) {
    if (verbose)
        std::cout << temp->get_name() << ' ' << temp->id() << std::endl;
    Data::EventType* p_item = m_dataModels.eventTypeModel().getById(temp->id());
    if (p_item == nullptr) {
        p_item = &(m_dataModels.eventTypeModel().add(*temp));
    } else {
        // do some updates
    }

    for (const Data::Event* i : temp->getEvents()) {
        importEvent(i, 1, p_item);
    }
    for (const Data::Group* i : temp->getGroups()) {
        importGroup(i, 1, p_item);
    }
    for (const Data::Race* i : temp->getRaces()) {
        importRace(i, 1, p_item);
    }
}



template <typename T>
void NavigationLoader::importEvent(const Data::Event* temp, int indent, T* parent)  {
    if (verbose)
        std::cout << std::string(indent,' ') << '[' << temp->get_name() << "] " << temp->id() << std::endl;
    Data::Event* p_item = m_dataModels.eventModel().getById(temp->id());
    if (p_item == nullptr) {
        p_item = &(m_dataModels.eventModel().add(*temp));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }



    for (Data::Event* i : temp->getEvents()) {
        importEvent(i, indent + 1, p_item);
    }
    for (Data::Group* i : temp->getGroups()) {
        importGroup(i, indent + 1, p_item);
    }
    for (Data::Market* i : temp->getMarkets()) {
        importMarket(i, indent + 1, p_item);
    }
}


template <typename T>
void NavigationLoader::importGroup(const Data::Group* temp, int indent, T* parent)  {
    if (verbose)
        std::cout << std::string(indent,' ') << '(' << temp->get_name() << ") " << temp->id() << std::endl;
    Data::Group* p_item = m_dataModels.groupModel().getById(temp->id());
    if (p_item == nullptr) {
        p_item = &(m_dataModels.groupModel().add(*temp));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }

    for (const Data::Event* i : temp->getEvents()) {
        importEvent(i, indent + 1, p_item);
    }
    for (const Data::Group* i : temp->getGroups()) {
        importGroup(i, indent + 1, p_item);
    }
}


template <typename T>
void NavigationLoader::importMarket(const Data::Market* temp, int indent, T* parent) {
    if (verbose)
        std::cout << std::string(indent,' ') << '<' << temp->name() << "> " << temp->id() << std::endl;
    Data::Market* p_item = m_dataModels.marketModel().getById(temp->id());
    if (p_item == nullptr) {
        p_item = &(m_dataModels.marketModel().add(*temp));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }

}

template <typename T>
void NavigationLoader::importRace(const Data::Race* temp, int indent, T* parent) {
    if (verbose)
        std::cout << std::string(indent,' ') << '{' << temp->get_name() << "} " << temp->id() << std::endl;
    Data::Race* p_item = m_dataModels.raceModel().getById(temp->id());
    if (p_item == nullptr) {
        p_item = &(m_dataModels.raceModel().add(*temp));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }
    for (const Data::Market* i : temp->getMarkets()) {
        importMarket(i, indent + 1, p_item);
    }
}


void NavigationLoader::processJSONRoot(const Json::Value& json) {
    for (const Json::Value& node : json["children"]) {
        processJSONEventType(node);
    }
}
void NavigationLoader::processJSONEventType(const Json::Value& json) {
    std::string name = json["name"].asString();
    std::string id = json["id"].asString();

    m_eventTypes.emplace_back(id, name);
    Data::EventType* item = &(m_eventTypes.back());
    for (const Json::Value& node : json["children"]) {
        if (node["type"].asString() == "EVENT")
            processJSONEvent(node, item);
        else if (node["type"].asString() == "GROUP")
            processJSONGroup(node, item);
        else if (node["type"].asString() == "RACE")
            processJSONRace(node, item);
    }
}

template <typename T>
void NavigationLoader::processJSONEvent(const Json::Value& json, T& parent) {
    std::string name = json["name"].asString();
    std::string id = json["id"].asString();
    std::string country_code = json["countryCode"].asString();
    m_event.emplace_back(id, name, country_code);
    Data::Event* item = &(m_event.back());
    parent->addChild(item);
    for (const Json::Value& node : json["children"]) {
        if (node["type"].asString() == "EVENT")
            processJSONEvent(node, item);
        else if (node["type"].asString() == "GROUP")
            processJSONGroup(node, item);
        else if (node["type"].asString() == "MARKET") {
            processJSONMarket(node, item);
        }
    }
}

template <typename T>
void NavigationLoader::processJSONRace(const Json::Value& json, T& parent) {
    std::string name = json["name"].asString();
    std::string id = json["id"].asString();
    std::string start_time = json["startTime"].asString();
    std::string venue = json["venue"].asString();
    std::string race_number;

    if (json.isMember("raceNumber"))
        race_number = json["raceNumber"].asString();
    std::string country_code = json["countryCode"].asString();

    m_race.emplace_back(id, name, start_time, venue, race_number, country_code);
    Data::Race* item = &(m_race.back());
    parent->addChild(item);

    for (const Json::Value& node : json["children"]) {
        if (node["type"].asString() == "MARKET")
            processJSONMarket(node, item);
    }
}

template <typename T>
void NavigationLoader::processJSONMarket(const Json::Value& json, T& parent) {
    std::string exchangeId = json["exchangeId"].asString();
    std::string id = json["id"].asString();
    std::string marketStartTime = json["marketStartTime"].asString();
    std::string marketType = json["marketType"].asString();
    std::string tmp = json["numberOfWinners"].asString();


    int numberOfWinners = 0;
    if (!tmp.empty())
        numberOfWinners = stoi(tmp);
    std::string name = json["name"].asString();

    m_markets.emplace_back(id, exchangeId, marketStartTime, marketType, numberOfWinners, name);
    Data::Market* item = &(m_markets.back());
    parent->addChild(item);
}

template <typename T>
void NavigationLoader::processJSONGroup(const Json::Value& json, T& parent) {
    std::string name = json["name"].asString();
    std::string id = json["id"].asString();
    m_group.emplace_back(id, name);
    Data::Group* item = &(m_group.back());
    parent->addChild(item);
    for (const Json::Value& node : json["children"]) {
        if (node["type"].asString() == "EVENT")
            processJSONEvent(node, item);
        else if (node["type"] == "GROUP")
            processJSONGroup(node, item);
    }
}

NavigationLoader::NavigationLoader(DataModels &dataModels) : m_dataModels(dataModels), verbose(false) {

}

