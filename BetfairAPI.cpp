//
// Created by scott on 22/01/2020.
//

#include <boost/property_tree/ptree.hpp>
#include <betting_type/MarketFilter.h>
#include <boost/property_tree/json_parser.hpp>
#include "BetfairAPI.h"
#include "Authentication.h"
#include <jsoncpp/json/json.h>
#include <betting_type/MarketCatalogue.h>
#include <string>
#include <betting_type/APINGException.h>

using boost::property_tree::ptree;
using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;

ReplaceExecutionReport BetfairAPI::replaceOrders(std::string marketId, std::forward_list<ReplaceInstruction> instructions,
                                                 std::optional<std::string> customerRef, std::optional<MarketVersion> marketVersion,
                                                 std::optional<bool> async)
{
    ReplaceExecutionReport result{};
    ptree tree;
    tree.put("id", "1");
    tree.put("jsonrpc", "2.0");
    tree.put("method", "SportsAPING/v1.0/replaceOrders");
    tree.put_child("params", boost::property_tree::ptree());

    tree.get_child("params").put("marketId", marketId);
    {
        ptree ntree;
        for (auto& item : instructions) {
            ntree.push_back(std::make_pair("",item.ptree()));
        }
        tree.get_child("params").put_child("instructions", ntree);
    }
    if (customerRef.has_value())
        tree.get_child("params").put("customerRef", customerRef.value());
    if (marketVersion.has_value())
        tree.get_child("params").put_child("marketVersion", marketVersion.value().ptree());
    if (async.has_value())
        tree.get_child("params").put("async", async.value());

    std::string json;
    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, tree);
    std::cout << ss.str();
    client.request(
            "POST",
            "/exchange/betting/json-rpc/v1",
            ss.str(),
            header,
            [&](const std::shared_ptr<HttpsClient::Response>& response,
                const SimpleWeb::error_code)
            {
                Json::Value root;
                response->content >> root;
                if (root.isMember("error")) {
                    throw APINGException(root["error"]["data"]["APINGException"]);
                }
                result = ReplaceExecutionReport(root["result"]);
            }
    );
    client.io_service->run();
    return result;
}



UpdateExecutionReport BetfairAPI::updateOrders(std::string marketId, std::forward_list<UpdateInstruction> instructions,
                                               std::optional<std::string> customerRef)
{
    UpdateExecutionReport result{};
    ptree tree;
    tree.put("id", "1");
    tree.put("jsonrpc", "2.0");
    tree.put("method", "SportsAPING/v1.0/updateOrders");
    tree.put_child("params", boost::property_tree::ptree());

    tree.get_child("params").put("marketId", marketId);
    {
        ptree ntree;
        for (auto& item : instructions) {
            ntree.push_back(std::make_pair("",item.ptree()));
        }
        tree.get_child("params").put_child("instructions", ntree);
    }
    if (customerRef.has_value())
        tree.get_child("params").put("customerRef", customerRef.value());

    std::string json;
    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, tree);
    std::cout << ss.str();
    client.request(
            "POST",
            "/exchange/betting/json-rpc/v1",
            ss.str(),
            header,
            [&](const std::shared_ptr<HttpsClient::Response>& response,
                const SimpleWeb::error_code)
            {
                Json::Value root;
                response->content >> root;
                if (root.isMember("error")) {
                    throw APINGException(root["error"]["data"]["APINGException"]);
                }
                result = UpdateExecutionReport(root["result"]);
            }
    );
    client.io_service->run();

    return result;
}


CancelExecutionReport BetfairAPI::cancelOrders(std::optional<std::string> marketId, std::optional<std::forward_list<CancelInstruction>> instructions, std::optional<std::string> customerRef)
{
    CancelExecutionReport result{};
    ptree tree;
    tree.put("id", "1");
    tree.put("jsonrpc", "2.0");
    tree.put("method", "SportsAPING/v1.0/cancelOrders");
    tree.put_child("params", boost::property_tree::ptree());

    if (marketId.has_value())
        tree.get_child("params").put("marketId", marketId.value());
    if (instructions.has_value())
    {
        ptree ntree;
        for (auto& item : instructions.value()) {
            ntree.push_back(std::make_pair("",item.ptree()));
        }
        tree.get_child("params").put_child("instructions", ntree);
    }
    if (customerRef.has_value())
        tree.get_child("params").put("customerRef", customerRef.value());

    std::string json;
    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, tree);
    std::cout << ss.str();
    client.request(
            "POST",
            "/exchange/betting/json-rpc/v1",
            ss.str(),
            header,
            [&](const std::shared_ptr<HttpsClient::Response>& response,
                const SimpleWeb::error_code)
            {
                Json::Value root;
                response->content >> root;
                if (root.isMember("error")) {
                    throw APINGException(root["error"]["data"]["APINGException"]);
                }
                result = CancelExecutionReport(root["result"]);
            }
    );
    client.io_service->run();


    return result;
}




CurrentOrderSummaryReport BetfairAPI::listCurrentOrders(std::optional<std::set<std::string>> betIds,
                                                        std::optional<std::set<std::string>> marketIds,
                                                        std::optional<std::string> orderProjection,
                                                        std::optional<std::set<std::string>> customerOrderRefs,
                                                        std::optional<std::set<std::string>> customerStrategyRefs,
                                                        std::optional<TimeRange> dateRange,
                                                        std::optional<std::string> orderBy,
                                                        std::optional<std::string> sortDir,
                                                        std::optional<int> fromRecord, std::optional<int> recordCount) {
    CurrentOrderSummaryReport result;

    ptree tree;
    tree.put("id", "1");
    tree.put("jsonrpc", "2.0");
    tree.put("method", "SportsAPING/v1.0/listCurrentOrders");
    tree.put_child("params", boost::property_tree::ptree());

    if (betIds.has_value())
    {
        ptree ntree;
        for (const auto& s : betIds.value()) {
            ptree child;
            child.put("", s);
            ntree.push_back(std::make_pair("", child));
        }
        tree.get_child("params").put_child("betIds", ntree);
    }
    if (marketIds.has_value())
    {
        ptree ntree;
        for (const auto& s : marketIds.value()) {
            ptree child;
            child.put("", s);
            ntree.push_back(std::make_pair("", child));
        }
        tree.get_child("params").put_child("marketIds", ntree);
    }
    if (orderProjection.has_value())
        tree.get_child("params").put("orderProjection", orderProjection.value());
    if (customerOrderRefs.has_value())
    {
        ptree ntree;
        for (const auto& s : customerOrderRefs.value()) {
            ptree child;
            child.put("", s);
            ntree.push_back(std::make_pair("", child));
        }
        tree.get_child("params").put_child("customerOrderRefs", ntree);
    }
    if (customerStrategyRefs.has_value())
    {
        ptree ntree;
        for (const auto& s : customerStrategyRefs.value()) {
            ptree child;
            child.put("", s);
            ntree.push_back(std::make_pair("", child));
        }
        tree.get_child("params").put_child("customerStrategyRefs", ntree);
    }
    if (dateRange.has_value())
        tree.get_child("params").put_child("dateRange", dateRange.value().ptree());
    if (orderBy.has_value())
        tree.get_child("params").put("orderBy", orderBy.value());
    if (sortDir.has_value())
        tree.get_child("params").put("sortDir", sortDir.value());
    if (fromRecord.has_value())
        tree.get_child("params").put("fromRecord", fromRecord.value());
    if (recordCount.has_value())
        tree.get_child("params").put("recordCount", recordCount.value());

    std::string json;
    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, tree);
    std::cout << ss.str();

    client.request(
            "POST",
            "/exchange/betting/json-rpc/v1",
            ss.str(),
            header,
            [&](const std::shared_ptr<HttpsClient::Response>& response,
                const SimpleWeb::error_code)
            {
                Json::Value root;
                response->content >> root;
                if (root.isMember("error")) {
                    throw APINGException(root["error"]["data"]["APINGException"]);
                }
                result = CurrentOrderSummaryReport(root["result"]);
            }
    );
    client.io_service->run();


    return result;
}



std::forward_list<MarketBook> BetfairAPI::listMarketBook(const std::forward_list<std::string>& marketIds, std::optional<PriceProjection> priceProjection,
                                                   std::optional<std::string> orderProjection, std::optional<std::string> matchProjection,
                                                   std::optional<bool> includeOverallPosition, std::optional<bool> partitionMatchedByStrategyRef,
                                                   std::optional<std::vector<std::string>> customerStrategyRefs,
                                                   std::optional<std::string> currencyCode, std::optional<std::string> locale,
                                                   std::optional<std::string> matchedSince, std::optional<std::vector<std::string>> betIds)
{

    std::forward_list<MarketBook> items;

    ptree tree;
    tree.put("id", "1");
    tree.put("jsonrpc", "2.0");
    tree.put("method", "SportsAPING/v1.0/listMarketBook");
    tree.put_child("params", boost::property_tree::ptree());

    {
        ptree ntree;
        for (const auto& s : marketIds) {
            ptree child;
            child.put("", s);
            ntree.push_back(std::make_pair("", child));
        }
        tree.get_child("params").put_child("marketIds", ntree);
    }
    if (priceProjection.has_value())
        tree.get_child("params").put_child("priceProjection", priceProjection.value().ptree());
    if (orderProjection.has_value())
        tree.get_child("params").put("orderProjection", orderProjection.value());
    if (matchProjection.has_value())
        tree.get_child("params").put("matchProjection", matchProjection.value());
    if (includeOverallPosition.has_value())
        tree.get_child("params").put("includeOverallPosition", includeOverallPosition.value());
    if (partitionMatchedByStrategyRef.has_value())
        tree.get_child("params").put("partitionMatchedByStrategyRef", partitionMatchedByStrategyRef.value());
    if (customerStrategyRefs.has_value()) {
        ptree ntree;
        for (auto s : customerStrategyRefs.value()) {
            ptree child;
            child.put("", s);
            ntree.push_back(std::make_pair("", child));
        }
        tree.get_child("params").put_child("customerStrategyRefs", ntree);
    }
    if (currencyCode.has_value())
        tree.get_child("params").put("currencyCode", currencyCode.value());
    if (locale.has_value())
        tree.get_child("params").put("locale", locale.value());
    if (matchedSince.has_value())
        tree.get_child("params").put("matchedSince", matchedSince.value());
    if (matchedSince.has_value())
        tree.get_child("params").put("matchedSince", matchedSince.value());
    if (betIds.has_value()) {
        ptree ntree;
        for (auto s : betIds.value()) {
            ptree child;
            child.put("", s);
            ntree.push_back(std::make_pair("", child));
        }
        tree.get_child("params").put_child("betIds", ntree);
    }


    std::string json;
    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, tree);
    std::cout << ss.str();

    client.io_service->reset();
    client.request(
            "POST",
            "/exchange/betting/json-rpc/v1",
            ss.str(),
            header,
            [&](const std::shared_ptr<HttpsClient::Response>& response,
                const SimpleWeb::error_code)
            {
                Json::Value root;
                response->content >> root;
                if (root.isMember("error")) {
                    throw APINGException(root["error"]["data"]["APINGException"]);
                }
                const Json::Value result = root["result"];
                for (const auto & index : result)
                {
                    items.emplace_front(MarketBook(index));
                }
            }
    );
    client.io_service->run();

    return items;
}

// https://docs.developer.betfair.com/display/1smk3cen4v3lu3yomq5qye0ni/placeOrders
PlaceExecutionReport BetfairAPI::placeOrders(const std::string& marketId, const std::vector<PlaceInstruction>& instructions, std::optional<std::string> customerRef,
                                             std::optional<MarketVersion> marketVersion, std::optional<std::string> customerStrategyRef, std::optional<bool> async) {

    PlaceExecutionReport result;

    ptree tree;
    tree.put("id", "1");
    tree.put("jsonrpc", "2.0");
    tree.put("method", "SportsAPING/v1.0/placeOrders");
    tree.put_child("params", boost::property_tree::ptree());
    tree.get_child("params").put("marketId",marketId);
    tree.get_child("params").put_child("instructions", boost::property_tree::ptree());
    if (customerRef.has_value())
        tree.get_child("params").put("customerRef",customerRef.value());
    if (marketVersion.has_value())
        tree.get_child("params").put_child("marketVersion", marketVersion.value().ptree());
    if (customerStrategyRef.has_value())
        tree.get_child("params").put("customerStrategyRef",customerStrategyRef.value());
    if (async.has_value())
        tree.get_child("params").put("async",async.value());



    for (auto& item : instructions) {
        tree.get_child("params").get_child("instructions").push_back(std::make_pair("",item.ptree()));
    }

    std::string json;
    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, tree);
    std::cout << ss.str();

    client.request(
            "POST",
            "/exchange/betting/json-rpc/v1",
            ss.str(),
            header,
            [&](const std::shared_ptr<HttpsClient::Response>& response,
                const SimpleWeb::error_code)
            {
                Json::Value root;
                response->content >> root;
                if (root.isMember("error")) {
                    throw APINGException(root["error"]["data"]["APINGException"]);
                }
                result = PlaceExecutionReport(root["result"]);
            }
    );
    client.io_service->run();


    return result;
}




std::forward_list<MarketCatalogue> BetfairAPI::listMarketCatalogue(const MarketFilter& filter, const std::set<std::string>& marketProjection, const std::string& sort, int maxResults, const std::string& locale) {

    std::forward_list<MarketCatalogue> items;

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
            [&](const std::shared_ptr<HttpsClient::Response>& response,
                const SimpleWeb::error_code)
            {
                Json::Value root;
                response->content >> root;
                if (root.isMember("error")) {
                    throw APINGException(root["error"]["data"]["APINGException"]);
                }
                const Json::Value result = root["result"];
                for (const auto & index : result)
                {
                    items.emplace_front(MarketCatalogue(index));
                }
            }
    );
    client.io_service->run();
    return items;
}

BetfairAPI::BetfairAPI():
        client("api.betfair.com:443", true)
{
    header.emplace("Accept", "application/json");
    header.emplace("Content-type", "application/json");
    header.emplace("X-Application", Authentication::applicationId);
    header.emplace("X-Authentication", Authentication::token);
}


