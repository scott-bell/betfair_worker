//
// Created by scott on 22/01/2020.
//

#include <boost/property_tree/ptree.hpp>
#include <betting_type/MarketFilter.h>
#include <boost/property_tree/json_parser.hpp>
#include "APILoader.h"
#include <jsoncpp/json/json.h>
#include <betting_type/MarketCatalogue.h>

using boost::property_tree::ptree;
using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;

std::vector<MarketCatalogue> APILoader::listMarketCatalogue(const MarketFilter& filter, const std::set<std::string>& marketProjection, const std::string& sort, int maxResults, const std::string& locale) {

    std::vector<MarketCatalogue> items;

    HttpsClient client("api.betfair.com:443", true);
    const std::string applicationId = ".";
    const std::string token = ".";

    SimpleWeb::CaseInsensitiveMultimap header;
    header.emplace("Accept", "application/json");
    header.emplace("Content-type", "application/json");
    header.emplace("X-Application", applicationId);
    header.emplace("X-Authentication", token);

    ptree tree;
    tree.put("id", "1");
    tree.put("jsonrpc", "2.0");
    tree.put("method", "SportsAPING/v1.0/listMarketCatalogue");
    tree.put_child("params", boost::property_tree::ptree());
    tree.get_child("params").put_child("filter", filter.ptree());
    tree.get_child("params").put_child("marketProjection", boost::property_tree::ptree());
    tree.get_child("params").put("sort", sort);
    tree.get_child("params").put("locale", locale);

    for (auto& item : marketProjection) {
        ptree child1;
        child1.put("",item);
        tree.get_child("params").get_child("marketProjection").push_back(std::make_pair("",child1));
    }

    tree.get_child("params").put("maxResults",maxResults);

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
                Json::Value root;
                response->content >> root;
                const Json::Value result = root["result"];
                for (const auto & index : result)
                {
                    items.emplace_back(MarketCatalogue(index));
                }
            }
    );
    client.io_service->run();
    return items;
}
