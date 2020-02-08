//
// Created by scott on 22/01/2020.
//

#include <betting_type/MarketFilter.h>
#include <boost/property_tree/json_parser.hpp>
#include "BetfairAPI.h"
#include "Authentication.h"
#include <jsoncpp/json/json.h>
#include <betting_type/MarketCatalogue.h>
#include <string>
#include <betting_type/APINGException.h>

using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;

ReplaceExecutionReport BetfairAPI::replaceOrders(const std::string& marketId, std::forward_list<ReplaceInstruction> instructions,
                                                 std::optional<std::string> customerRef, std::optional<MarketVersion> marketVersion,
                                                 std::optional<bool> async)
{
    ReplaceExecutionReport result{};

    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/replaceOrders";

    Json::Value jsonParams;

    jsonParams["marketId"] = marketId;
    {
        Json::Value nested;
        for (const auto& s : instructions) {
            nested.append(s.json());
        }
        jsonParams["instructions"] = nested;
    }

    if (customerRef.has_value())
        jsonParams["customerRef"] = customerRef.value();
    if (marketVersion.has_value())
        jsonParams["marketVersion"] = marketVersion.value().json();
    if (async.has_value())
        jsonParams["async"] = async.value();


    json["params"] = jsonParams;

    Json::StyledWriter styledWriter;
    std::stringstream ss;
    ss << styledWriter.write(json);
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
    client.io_service->stop();
    return result;
}



UpdateExecutionReport BetfairAPI::updateOrders(std::string marketId, std::forward_list<UpdateInstruction> instructions,
                                               std::optional<std::string> customerRef)
{
    UpdateExecutionReport result{};
    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/updateOrders";

    Json::Value jsonParams;

    jsonParams["marketId"] = marketId;
    {
        Json::Value nested;
        for (auto& item : instructions) {
            nested.append(item.json());
        }
        jsonParams["instructions"]=nested;
    }
    if (customerRef.has_value())
        jsonParams["customerRef"]=customerRef.value();

    json["params"] = jsonParams;

    Json::StyledWriter styledWriter;
    std::stringstream ss;
    ss << styledWriter.write(json);
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
    client.io_service->stop();

    return result;
}


CancelExecutionReport BetfairAPI::cancelOrders(std::optional<std::string> marketId, std::optional<std::forward_list<CancelInstruction>> instructions, std::optional<std::string> customerRef)
{
    CancelExecutionReport result{};
    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/cancelOrders";

    Json::Value jsonParams;

    if (marketId.has_value())
        jsonParams["marketId"] = marketId.value();
    if (instructions.has_value())
    {
        Json::Value nested;
        for (auto& item : instructions.value()) {
            nested.append(item.json());
        }
        jsonParams["instructions"] = nested;
    }
    if (customerRef.has_value())
        jsonParams["customerRef"] = customerRef.value();

    json["params"] = jsonParams;

    Json::StyledWriter styledWriter;
    std::stringstream ss;
    ss << styledWriter.write(json);
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
    client.io_service->stop();


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

    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/listCurrentOrders";

    Json::Value jsonParams;

    if (betIds.has_value())
    {
        Json::Value nested;
        for (const auto& s : betIds.value()) {
            nested.append(s);
        }
        jsonParams["betIds"] = nested;
    }
    if (marketIds.has_value())
    {
        Json::Value nested;
        for (const auto& s : marketIds.value()) {
            nested.append(s);
        }
        jsonParams["marketIds"] = nested;
    }
    if (orderProjection.has_value())
        jsonParams["orderProjection"] = orderProjection.value();
    if (customerOrderRefs.has_value())
    {
        Json::Value nested;
        for (const auto& s : customerOrderRefs.value()) {
            nested.append(s);
        }
        jsonParams["customerOrderRefs"]= nested;
    }
    if (customerStrategyRefs.has_value())
    {
        Json::Value nested;
        for (const auto& s : customerStrategyRefs.value()) {
            nested.append(s);
        }
        jsonParams["customerStrategyRefs"]= nested;
    }
    if (dateRange.has_value())
        jsonParams["dateRange"] = dateRange.value().json();
    if (orderBy.has_value())
        jsonParams["orderBy"] = orderBy.value();
    if (sortDir.has_value())
        jsonParams["sortDir"] = sortDir.value();
    if (fromRecord.has_value())
        jsonParams["fromRecord"] = fromRecord.value();
    if (recordCount.has_value())
        jsonParams["recordCount"] = recordCount.value();

    json["params"] = jsonParams;

    Json::StyledWriter styledWriter;
    std::stringstream ss;
    ss << styledWriter.write(json);
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
                Json::Value a = root["result"];
                result = CurrentOrderSummaryReport(root["result"]);
            }
    );
    client.io_service->run();
    client.io_service->stop();

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

    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/listMarketBook";

    Json::Value jsonParams;

    {
        Json::Value jsonMarkets;
        for (const auto& s : marketIds) {
            jsonMarkets.append(s);
        }
        jsonParams["marketIds"] = jsonMarkets;
    }

    if (priceProjection.has_value())
        jsonParams["priceProjection"] = priceProjection.value().json();
    if (orderProjection.has_value())
        jsonParams["orderProjection"] = orderProjection.value();
    if (matchProjection.has_value())
        jsonParams["matchProjection"] = matchProjection.value();
    if (includeOverallPosition.has_value())
        jsonParams["includeOverallPosition"] = includeOverallPosition.value();
    if (partitionMatchedByStrategyRef.has_value())
        jsonParams["partitionMatchedByStrategyRef"] = partitionMatchedByStrategyRef.value();
    if (customerStrategyRefs.has_value()) {
        Json::Value nested;
        for (auto s : customerStrategyRefs.value()) {
            nested.append(s);
        }
        jsonParams["customerStrategyRefs"] = nested;
    }
    if (currencyCode.has_value())
        jsonParams["currencyCode"] = currencyCode.value();
    if (locale.has_value())
        jsonParams["locale"] = locale.value();
    if (matchedSince.has_value())
        jsonParams["matchedSince"] = matchedSince.value();
    if (betIds.has_value()) {
        Json::Value nested;
        for (auto s : betIds.value()) {
            nested.append(s);
        }
        jsonParams["betIds"] = nested;
    }

    json["params"] = jsonParams;

    Json::StyledWriter styledWriter;
    std::stringstream ss;
    ss << styledWriter.write(json);
    std::cout << ss.str() << std::endl;

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
                    if ((root["error"].isMember("data")) && (root["error"]["data"].isMember("APINGException"))) {
                        throw APINGException(root["error"]["data"]["APINGException"]);
                    } else {
                        std::string err = root["error"]["code"].asString() + " " + root["error"]["message"].asCString();
                        throw std::runtime_error(err);
                    }
                }
                const Json::Value result = root["result"];
                for (const auto & index : result)
                {
                    items.emplace_front(MarketBook(index));
                }
            }
    );
    client.io_service->run();
    client.io_service->stop();

    return items;
}

// https://docs.developer.betfair.com/display/1smk3cen4v3lu3yomq5qye0ni/placeOrders
PlaceExecutionReport BetfairAPI::placeOrders(const std::string& marketId, const std::vector<PlaceInstruction>& instructions, std::optional<std::string> customerRef,
                                             std::optional<MarketVersion> marketVersion, std::optional<std::string> customerStrategyRef, std::optional<bool> async) {

    PlaceExecutionReport result;

    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/placeOrders";

    Json::Value jsonParams;



    jsonParams["marketId"]=marketId;
    if (customerRef.has_value())
        jsonParams["customerRef"]=customerRef.value();
    if (marketVersion.has_value())
        jsonParams["marketVersion"]=marketVersion.value().json();
    if (customerStrategyRef.has_value())
        jsonParams["customerStrategyRef"]=customerStrategyRef.value();
    if (async.has_value())
        jsonParams["async"]=async.value();

    {
        Json::Value nested;
        for (auto &item : instructions) {
            nested.append(item.json());
        }
        jsonParams["instructions"] = nested;

    }

    json["params"] = jsonParams;

    Json::StyledWriter styledWriter;
    std::stringstream ss;
    ss << styledWriter.write(json);
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
    client.io_service->stop();


    return result;
}




std::forward_list<MarketCatalogue> BetfairAPI::listMarketCatalogue(const MarketFilter& filter, const std::set<std::string>& marketProjection, const std::string& sort, int maxResults, const std::string& locale) {

    std::forward_list<MarketCatalogue> items;

    Json::Value json;
    json["id"] = "1";
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/listMarketCatalogue";

    Json::Value jsonParams;

    jsonParams["filter"] = filter.json();

    jsonParams["sort"] = sort;
    jsonParams["locale"] = locale;


    {
        Json::Value nested;
        for (auto &s : marketProjection) {
            nested.append(s);
        }
        jsonParams["marketProjection"]= nested;

    }

    jsonParams["maxResults"] = maxResults;

    json["params"] = jsonParams;

    Json::StyledWriter styledWriter;
    std::stringstream ss;
    ss << styledWriter.write(json);
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
    client.io_service->stop();
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


