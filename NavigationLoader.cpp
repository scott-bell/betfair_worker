//
// Created by scott on 17/01/2020.
//

#include "NavigationLoader.h"
#include "Authentication.h"

using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;


void NavigationLoader::init() {
    m_betfairMarkets.reserve(30000);
    m_betfairEvent.reserve(5000);
    m_betfairRace.reserve(1000);
    m_betfairGroup.reserve(1000);
    m_betfairEventTypes.reserve(100);

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
                        unsigned long node_count = m_betfairMarkets.size() + m_betfairEvent.size() + m_betfairRace.size() + m_betfairGroup.size() + m_betfairEventTypes.size();
                        std::cout <<    "Parsed JSON in " << duration << ". "
                                        "Markets: " << m_betfairMarkets.size() <<
                                        ", events: " << m_betfairEvent.size() <<
                                        ", races: " << m_betfairRace.size() <<
                                        ", groups: " << m_betfairGroup.size() <<
                                        ", event types: " << m_betfairEventTypes.size()<<
                                        ", total: " << node_count <<
                                        std::endl;
                    }
                }
            });
    client.io_service->run();
    importRoot();
}

void NavigationLoader::importRoot() {
    for (const BetfairEventType& item : m_betfairEventTypes) {
        importEventType(&item);
    }
}

void NavigationLoader::importEventType(const BetfairEventType* temp) {
    if (verbose)
        std::cout << temp->get_name() << ' ' << temp->get_id() << std::endl;
    BetfairEventType* p_item = m_betfair_data.eventTypeModel().getById(temp->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.eventTypeModel().add(*temp));
    } else {
        // do some updates
    }

    for (const BetfairEvent* i : temp->getBetfairEvents()) {
        importEvent(i, 1, p_item);
    }
    for (const BetfairGroup* i : temp->getBetfairGroups()) {
        importGroup(i, 1, p_item);
    }
    for (const BetfairRace* i : temp->getBetfairRaces()) {
        importRace(i, 1, p_item);
    }
}



template <typename T>
void NavigationLoader::importEvent(const BetfairEvent* temp, int indent, T* parent)  {
    if (verbose)
        std::cout << std::string(indent,' ') << '[' << temp->get_name() << "] " << temp->get_id() << std::endl;
    BetfairEvent* p_item = m_betfair_data.eventModel().getById(temp->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.eventModel().add(*temp));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }



    for (BetfairEvent* i : temp->getBetfairEvents()) {
        importEvent(i, indent + 1, p_item);
    }
    for (BetfairGroup* i : temp->getBetfairGroups()) {
        importGroup(i, indent + 1, p_item);
    }
    for (BetfairMarket* i : temp->getBetfairMarkets()) {
        importMarket(i, indent + 1, p_item);
    }
}


template <typename T>
void NavigationLoader::importGroup(const BetfairGroup* temp, int indent, T* parent)  {
    if (verbose)
        std::cout << std::string(indent,' ') << '(' << temp->get_name() << ") " << temp->get_id() << std::endl;
    BetfairGroup* p_item = m_betfair_data.groupModel().getById(temp->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.groupModel().add(*temp));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }

    for (const BetfairEvent* i : temp->getBetfairEvents()) {
        importEvent(i, indent + 1, p_item);
    }
    for (const BetfairGroup* i : temp->getBetfairGroups()) {
        importGroup(i, indent + 1, p_item);
    }
}


template <typename T>
void NavigationLoader::importMarket(const BetfairMarket* temp, int indent, T* parent) {
    if (verbose)
        std::cout << std::string(indent,' ') << '<' << temp->name() << "> " << temp->get_id() << std::endl;
    BetfairMarket* p_item = m_betfair_data.marketModel().getById(temp->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.marketModel().add(*temp));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }

}

template <typename T>
void NavigationLoader::importRace(const BetfairRace* temp, int indent, T* parent) {
    if (verbose)
        std::cout << std::string(indent,' ') << '{' << temp->get_name() << "} " << temp->get_id() << std::endl;
    BetfairRace* p_item = m_betfair_data.raceModel().getById(temp->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.raceModel().add(*temp));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }
    for (const BetfairMarket* i : temp->getBetfairMarkets()) {
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

    m_betfairEventTypes.emplace_back(id, name);
    BetfairEventType* item = &(m_betfairEventTypes.back());
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
    m_betfairEvent.emplace_back(id, name, country_code);
    BetfairEvent* item = &(m_betfairEvent.back());
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

    m_betfairRace.emplace_back(id, name, start_time, venue, race_number, country_code);
    BetfairRace* item = &(m_betfairRace.back());
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

    m_betfairMarkets.emplace_back(id, exchangeId, marketStartTime, marketType, numberOfWinners, name);
    BetfairMarket* item = &(m_betfairMarkets.back());
    parent->addChild(item);
}

template <typename T>
void NavigationLoader::processJSONGroup(const Json::Value& json, T& parent) {
    std::string name = json["name"].asString();
    std::string id = json["id"].asString();
    m_betfairGroup.emplace_back(id,name);
    BetfairGroup* item = &(m_betfairGroup.back());
    parent->addChild(item);
    for (const Json::Value& node : json["children"]) {
        if (node["type"].asString() == "EVENT")
            processJSONEvent(node, item);
        else if (node["type"] == "GROUP")
            processJSONGroup(node, item);
    }
}

NavigationLoader::NavigationLoader(BetfairData &betfair_data) : m_betfair_data(betfair_data), verbose(false) {

}

