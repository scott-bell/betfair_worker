//
// Created by scott on 22/01/2020.
//

#include <boost/property_tree/ptree.hpp>
#include <betfair_data/MarketFilter.h>
#include <boost/property_tree/json_parser.hpp>
#include "APILoader.h"

using boost::property_tree::ptree;
using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;

void APILoader::listMarketCatalogue() {

    HttpsClient client("api.betfair.com:443", true);
    const std::string applicationId = ".";
    const std::string token = ".=";

    SimpleWeb::CaseInsensitiveMultimap header;
    header.emplace("Accept", "application/json");
    header.emplace("Content-type", "application/json");
    header.emplace("X-Application", applicationId);
    header.emplace("X-Authentication", token);

    MarketFilter filter{};
    //filter.m_withOrders = { "EXECUTION_COMPLETE", "EXECUTABLE" };
    filter.m_marketIds = { "1.167425942"};

    ptree tree;
    tree.put("id", "1");
    tree.put("jsonrpc", "2.0");
    tree.put("method", "SportsAPING/v1.0/listMarketCatalogue");
    tree.put_child("params", boost::property_tree::ptree());
    tree.get_child("params").put_child("filter", filter.ptree());

    std::set<std::string> marketProjection = {"COMPETITION", "EVENT", "EVENT_TYPE", "MARKET_START_TIME", "MARKET_DESCRIPTION", "RUNNER_DESCRIPTION", "RUNNER_METADATA"};
    tree.get_child("params").put_child("marketProjection", boost::property_tree::ptree());

    for (auto& item : marketProjection) {
        ptree child1;
        child1.put("",item);
        tree.get_child("params").get_child("marketProjection").push_back(std::make_pair("",child1));
    }

    tree.get_child("params").put("maxResults",10);

    std::string json;
    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, tree);
    std::cout << ss.str();

    client.request(
            "POST",
            "/exchange/betting/json-rpc/v1",
            ss.str(),
            header,
            [&](std::shared_ptr<HttpsClient::Response> response,
                const SimpleWeb::error_code &ec)
            {
                std::cout << response->content.string() << std::endl;

                //boost::property_tree::json_parser::write_json(ss, tree);
                /*ptree responseTree;
                std::stringstream ssInput;
                ssInput << response->content.string();
                boost::property_tree::read_json(ssInput, responseTree);

                auto x = responseTree.get<std::string>("jsonrpc");
                std::cout << x << std::endl;*/


            }
    );
    client.io_service->run();

}
