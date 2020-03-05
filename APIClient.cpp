//
// Created by scott on 22/01/2020.
//

#include <api_data/MarketFilter.h>
#include <boost/property_tree/json_parser.hpp>
#include "APIClient.h"
#include "Authentication.h"
#include <jsoncpp/json/json.h>
#include <api_data/MarketCatalogue.h>
#include <string>
#include <api_data/APINGException.h>

using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;

API::ReplaceExecutionReport APIClient::replaceOrders(const std::string& marketId, std::forward_list<API::ReplaceInstruction> instructions,
                                                     std::optional<std::string> customerRef, std::optional<API::MarketVersion> marketVersion,
                                                     std::optional<bool> async)
{
    HttpsClient client(url, true);
    API::ReplaceExecutionReport result{};

    std::cout << "replaceOrders" << std::endl;

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
    if (verbose)
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
                    throw API::APINGException(root["error"]["data"]["APINGException"]);
                }
                result = API::ReplaceExecutionReport(root["result"]);
            }
    );
    client.io_service->run();
    client.io_service->stop();
    return result;
}



API::UpdateExecutionReport APIClient::updateOrders(std::string marketId, std::forward_list<API::UpdateInstruction> instructions,
                                                   std::optional<std::string> customerRef)
{
    HttpsClient client(url, true);
    API::UpdateExecutionReport result{};
    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/updateOrders";
    std::cout << "updateOrders" << std::endl;

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
    if (verbose)
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
                    throw API::APINGException(root["error"]["data"]["APINGException"]);
                }
                result = API::UpdateExecutionReport(root["result"]);
            }
    );
    client.io_service->run();
    client.io_service->stop();

    return result;
}


API::CancelExecutionReport APIClient::cancelOrders(std::optional<std::string> marketId, std::optional<std::forward_list<API::CancelInstruction>> instructions, std::optional<std::string> customerRef)
{
    HttpsClient client(url, true);
    API::CancelExecutionReport result{};
    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/cancelOrders";

    std::cout << "cancelOrders" << std::endl;

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
    if (verbose)
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
                    throw API::APINGException(root["error"]["data"]["APINGException"]);
                }
                result = API::CancelExecutionReport(root["result"]);
            }
    );
    client.io_service->run();
    client.io_service->stop();


    return result;
}

API::ClearedOrderSummaryReport
APIClient::listClearedOrders(const std::string& betStatus, std::optional<std::set<std::string>> eventTypeIds,
                             std::optional<std::set<std::string>> eventIds,
                             std::optional<std::set<std::string>> marketIds,
                             std::optional<std::set<std::string>> runnerIds,
                             std::optional<std::vector<std::string>> betIds, std::optional<std::string> side,
                             std::optional<API::TimeRange> timeRange, std::optional<std::string> groupBy,
                             std::optional<bool> includeItemDescription, std::optional<std::string> locale,
                             std::optional<int> fromRecord, std::optional<int> recordCount)
{
    HttpsClient client(url, true);
    API::ClearedOrderSummaryReport result;

    std::cout << "listClearedOrders" << std::endl;


    Json::Value json;
    json["id"] = 1;
    json["jsonrpc"] = "2.0";
    json["method"] = "SportsAPING/v1.0/listClearedOrders";
    Json::Value jsonParams;

    jsonParams["betStatus"] = betStatus;

    if (eventTypeIds.has_value())
    {
        Json::Value nested;
        for (const auto& s : eventTypeIds.value()) {
            nested.append(s);
        }
        jsonParams["betIds"] = nested;
    }
    if (eventIds.has_value())
    {
        Json::Value nested;
        for (const auto& s : eventIds.value()) {
            nested.append(s);
        }
        jsonParams["eventIds"] = nested;
    }
    if (marketIds.has_value())
    {
        Json::Value nested;
        for (const auto& s : marketIds.value()) {
            nested.append(s);
        }
        jsonParams["marketIds"] = nested;
    }
    if (runnerIds.has_value())
    {
        Json::Value nested;
        for (const auto& s : runnerIds.value()) {
            nested.append(s);
        }
        jsonParams["runnerIds"] = nested;
    }
    if (betIds.has_value())
    {
        Json::Value nested;
        for (const auto& s : betIds.value()) {
            nested.append(s);
        }
        jsonParams["betIds"] = nested;
    }
    if (side.has_value())
        jsonParams["side"] = side.value();
    if (timeRange.has_value())
        jsonParams["timeRange"] = timeRange.value().json();
    if (groupBy.has_value())
        jsonParams["groupBy"] = groupBy.value();
    if (includeItemDescription.has_value())
        jsonParams["includeItemDescription"] = includeItemDescription.value();
    if (locale.has_value())
        jsonParams["locale"] = locale.value();
    if (side.has_value())
        jsonParams["side"] = side.value();
    if (fromRecord.has_value())
        jsonParams["fromRecord"] = fromRecord.value();
    if (recordCount.has_value())
        jsonParams["recordCount"] = recordCount.value();

    json["params"] = jsonParams;
    Json::StyledWriter styledWriter;
    std::stringstream ss;
    ss << styledWriter.write(json);
    if (verbose)
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
                    throw API::APINGException(root["error"]["data"]["APINGException"]);
                }
                result = API::ClearedOrderSummaryReport(root["result"]);
            }
    );
    client.io_service->run();

    return result;
}


API::CurrentOrderSummaryReport APIClient::listCurrentOrders(std::optional<std::set<std::string>> betIds,
                                                            std::optional<std::set<std::string>> marketIds,
                                                            std::optional<std::string> orderProjection,
                                                            std::optional<std::set<std::string>> customerOrderRefs,
                                                            std::optional<std::set<std::string>> customerStrategyRefs,
                                                            std::optional<API::TimeRange> dateRange,
                                                            std::optional<std::string> orderBy,
                                                            std::optional<std::string> sortDir,
                                                            std::optional<int> fromRecord, std::optional<int> recordCount) {
    HttpsClient client(url, true);
    API::CurrentOrderSummaryReport result;

    std::cout << "listCurrentOrders" << std::endl;

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
    if (verbose)
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
                    throw API::APINGException(root["error"]["data"]["APINGException"]);
                }
                Json::Value a = root["result"];
                result = API::CurrentOrderSummaryReport(root["result"]);
            }
    );
    client.io_service->run();

    return result;
}



std::forward_list<API::MarketBook> APIClient::listMarketBook(const std::forward_list<std::string>& marketIds, std::optional<API::PriceProjection> priceProjection,
                                                             std::optional<std::string> orderProjection, std::optional<std::string> matchProjection,
                                                             std::optional<bool> includeOverallPosition, std::optional<bool> partitionMatchedByStrategyRef,
                                                             std::optional<std::vector<std::string>> customerStrategyRefs,
                                                             std::optional<std::string> currencyCode, std::optional<std::string> locale,
                                                             std::optional<std::string> matchedSince, std::optional<std::vector<std::string>> betIds)
{
    HttpsClient client(url, true);
    std::forward_list<API::MarketBook> items;

    std::cout << "listMarketBook" << std::endl;

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
    if (verbose)
        std::cout << ss.str() << std::endl;

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
                        throw API::APINGException(root["error"]["data"]["APINGException"]);
                    } else {
                        std::string err = root["error"]["code"].asString() + " " + root["error"]["message"].asCString();
                        throw std::runtime_error(err);
                    }
                }
                const Json::Value result = root["result"];
                for (const auto & index : result)
                {
                    items.emplace_front(API::MarketBook(index));
                }
            }
    );
    client.io_service->run();

    return items;
}

API::PlaceExecutionReport APIClient::placeOrders(const std::string& marketId, const std::vector<API::PlaceInstruction>& instructions, std::optional<std::string> customerRef,
                                                 std::optional<API::MarketVersion> marketVersion, std::optional<std::string> customerStrategyRef, std::optional<bool> async) {

    HttpsClient client(url, true);
    API::PlaceExecutionReport result;

    std::cout << "placeOrders" << std::endl;

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
    if (verbose)
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
                    throw API::APINGException(root["error"]["data"]["APINGException"]);
                }
                result = API::PlaceExecutionReport(root["result"]);
            }
    );
    client.io_service->run();
    client.io_service->stop();


    return result;
}




std::forward_list<API::MarketCatalogue> APIClient::listMarketCatalogue(const API::MarketFilter& filter, const std::set<std::string>& marketProjection, const std::string& sort, int maxResults, const std::string& locale) {

    HttpsClient client(url, true);
    std::forward_list<API::MarketCatalogue> items;

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
    if (verbose)
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
                    throw API::APINGException(root["error"]["data"]["APINGException"]);
                }
                const Json::Value result = root["result"];
                for (const auto & index : result)
                {
                    items.emplace_front(API::MarketCatalogue(index));
                }
            }
    );
    client.io_service->run();
    client.io_service->stop();
    return items;
}

APIClient::APIClient():
        url("api.betfair.com:443")
{
    header.emplace("Accept", "application/json");
    header.emplace("Content-type", "application/json");
    header.emplace("X-Application", Authentication::applicationId);
    header.emplace("X-Authentication", Authentication::token);
}