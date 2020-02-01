//
// Created by scott on 17/01/2020.
//

#include "NavigationLoader.h"
#include "Authentication.h"

using boost::property_tree::ptree;
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
                    boost::property_tree::ptree parseTree;
                    {
                        auto t1 = std::chrono::high_resolution_clock::now();
                        std::cout << "Parsing JSON structure ... " << response->content.size() << " bytes" << std::endl;
                        boost::property_tree::read_json(response->content, parseTree);
                        auto t2 = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
                        std::cout << "Parsed JSON in " << duration << std::endl;
                    }
                    {
                        auto t1 = std::chrono::high_resolution_clock::now();
                        std::string type = parseTree.get<std::string>("type");
                        std::string name = parseTree.get<std::string>("name");
                        std::cout << "Recursing through json..." << std::endl;
                        processJSONRoot(parseTree);
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
        importEventType(item);
    }
}

void NavigationLoader::importEventType(const BetfairEventType& item) {
    if (verbose)
        std::cout << item.get_name() << ' ' << item.get_id() << std::endl;
    BetfairEventType* p_item = m_betfair_data.getBetfairEventType(item.get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.addEventType(item.get_id(), item.get_name()));
    } else {
        // do some updates
    }

    for (BetfairEvent* i : item.getBetfairEvents()) {
        importEvent(i, 1, p_item);
    }
    for (BetfairGroup* i : item.getBetfairGroups()) {
        importGroup(i, 1, p_item);
    }
    for (BetfairRace* i : item.getBetfairRaces()) {
        importRace(i, 1, p_item);
    }
}



template <typename T>
void NavigationLoader::importEvent(const BetfairEvent* item, int indent, T& parent)  {
    if (verbose)
        std::cout << std::string(indent,' ') << '[' << item->get_name() << "] " << item->get_id() << std::endl;
    BetfairEvent* p_item = m_betfair_data.getBetfairEvent(item->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.addEvent(item->get_id(), item->get_name(), item->get_country_code()));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }

    for (BetfairEvent* i : item->getBetfairEvents()) {
        importEvent(i, indent + 1, p_item);
    }
    for (BetfairGroup* i : item->getBetfairGroups()) {
        importGroup(i, indent + 1, p_item);
    }
    for (BetfairMarket* i : item->getBetfairMarkets()) {
        importMarket(i, indent + 1, p_item);
    }
}


template <typename T>
void NavigationLoader::importGroup(const BetfairGroup* item, int indent, T& parent)  {
    if (verbose)
        std::cout << std::string(indent,' ') << '(' << item->get_name() << ") " << item->get_id() << std::endl;
    BetfairGroup* p_item = m_betfair_data.getBetfairGroup(item->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.addGroup(item->get_id(), item->get_name()));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }

    for (BetfairEvent* i : item->getBetfairEvents()) {
        importEvent(i, indent + 1, p_item);
    }
    for (BetfairGroup* i : item->getBetfairGroups()) {
        importGroup(i, indent + 1, p_item);
    }
}


template <typename T>
void NavigationLoader::importMarket(const BetfairMarket* item, int indent, T& parent) {
    if (verbose)
        std::cout << std::string(indent,' ') << '<' << item->name() << "> " << item->get_id() << std::endl;
    BetfairMarket* p_item = m_betfair_data.getBetfairMarket(item->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.addMarket(
                item->get_id(), item->exchangeId(), item->startTime(), item->marketType(),
                item->numberOfWinners(), item->name()
        ));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }

}

template <typename T>
void NavigationLoader::importRace(const BetfairRace* item, int indent, T& parent) {
    if (verbose)
        std::cout << std::string(indent,' ') << '{' << item->get_name() << "} " << item->get_id() << std::endl;
    BetfairRace* p_item = m_betfair_data.getBetfairRace(item->get_id());
    if (p_item == nullptr) {
        p_item = &(m_betfair_data.addRace(item->get_id(), item->get_name(), item->get_start_time(), item->get_venue(),
                                          item->get_race_number(), item->get_country_code()));
        parent->addChild(p_item);
    } else {
        parent->addChild(p_item);
    }
    for (BetfairMarket* i : item->getBetfairMarkets()) {
        importMarket(i, indent + 1, p_item);
    }
}


void NavigationLoader::processJSONRoot(const boost::property_tree::ptree& parseTree) {
    for (auto& node : parseTree.get_child("children")) {
        processJSONEventType(node.second);
    }
}
void NavigationLoader::processJSONEventType(const boost::property_tree::ptree& parseTree) {
    std::string name = parseTree.get<std::string>("name");
    std::string id = parseTree.get<std::string>("id");

    m_betfairEventTypes.emplace_back(id, name);
    BetfairEventType* item = &(m_betfairEventTypes.back());
    for (auto& node : parseTree.get_child("children")) {
        if (node.second.get<std::string>("type") == "EVENT")
            processJSONEvent(node.second, item);
        else if (node.second.get<std::string>("type") == "GROUP")
            processJSONGroup(node.second, item);
        else if (node.second.get<std::string>("type") == "RACE")
            processJSONRace(node.second, item);
    }
}

template <typename T>
void NavigationLoader::processJSONEvent(const boost::property_tree::ptree& parseTree, T& parent) {
    std::string name = parseTree.get<std::string>("name");
    std::string id = parseTree.get<std::string>("id");
    std::string country_code = parseTree.get<std::string>("countryCode");
    m_betfairEvent.emplace_back(id, name, country_code);
    BetfairEvent* item = &(m_betfairEvent.back());
    parent->addChild(item);
    for (auto& node : parseTree.get_child("children")) {
        if (node.second.get<std::string>("type") == "EVENT")
            processJSONEvent(node.second, item);
        else if (node.second.get<std::string>("type") == "GROUP")
            processJSONGroup(node.second, item);
        else if (node.second.get<std::string>("type") == "MARKET") {
            processJSONMarket(node.second, item);
        }
    }
}

template <typename T>
void NavigationLoader::processJSONRace(const boost::property_tree::ptree& parseTree, T& parent) {
    std::string name = parseTree.get<std::string>("name");
    std::string temp = parseTree.get<std::string>("id");
    std::string id = parseTree.get<std::string>("id");
    std::string start_time = parseTree.get<std::string>("startTime");
    std::string venue = parseTree.get<std::string>("venue");
    std::string race_number;

    if (parseTree.get_optional<std::string>("raceNumber"))
        race_number = parseTree.get<std::string>("raceNumber");
    std::string country_code = parseTree.get<std::string>("countryCode");

    m_betfairRace.emplace_back(id, name, start_time, venue, race_number, country_code);
    BetfairRace* item = &(m_betfairRace.back());
    parent->addChild(item);

    for (auto& node : parseTree.get_child("children")) {
        if (node.second.get<std::string>("type") == "MARKET")
            processJSONMarket(node.second, item);
    }
}

template <typename T>
void NavigationLoader::processJSONMarket(const boost::property_tree::ptree& parseTree, T& parent) {
    std::string exchangeId = parseTree.get<std::string>("exchangeId");
    std::string id = parseTree.get<std::string>("id");
    std::string marketStartTime = parseTree.get<std::string>("marketStartTime");
    std::string marketType = parseTree.get<std::string>("marketType");
    std::string tmp = parseTree.get<std::string>("numberOfWinners");


    int numberOfWinners = 0;
    if (!tmp.empty())
        numberOfWinners = stoi(tmp);
    std::string name = parseTree.get<std::string>("name");

    m_betfairMarkets.emplace_back(id, exchangeId, marketStartTime, marketType, numberOfWinners, name);
    BetfairMarket* item = &(m_betfairMarkets.back());
    parent->addChild(item);
}

template <typename T>
void NavigationLoader::processJSONGroup(const boost::property_tree::ptree& parseTree, T& parent) {
    std::string name = parseTree.get<std::string>("name");
    std::string id = parseTree.get<std::string>("id");
    m_betfairGroup.emplace_back(id,name);
    BetfairGroup* item = &(m_betfairGroup.back());
    parent->addChild(item);
    for (auto& node : parseTree.get_child("children")) {
        if (node.second.get<std::string>("type") == "EVENT")
            processJSONEvent(node.second, item);
        else if (node.second.get<std::string>("type") == "GROUP")
            processJSONGroup(node.second, item);
    }
}

NavigationLoader::NavigationLoader(BetfairData &betfair_data) : m_betfair_data(betfair_data), verbose(false) {

}

