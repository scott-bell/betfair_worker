//
// Created by scott on 31/01/2020.
//

#include <jsoncpp/json/json.h>
#include "data_models/MarketFilter.h"
#include "data_models/Sorter.h"
#include "data_models/MarketSorter.h"
#include "WebServer.h"
#include "Utility.h"


template <typename T, typename C, typename F, typename S>
void WebServer::addResource(HttpServer& server, const std::string& path, C& container) {

    server.resource["^/" + path + "/([0-9.:]+)"]["OPTIONS"] = [&](std::shared_ptr<HttpServer::Response> response, const std::shared_ptr<HttpServer::Request>& /*request*/) {
        *response   << "HTTP/1.1 200 OK\r\n"
                    << "Access-Control-Allow-Origin: *\r\n"
                    << "Access-Control-Allow-Methods:: GET\r\n"
                    << "\r\n";
    };

    server.resource["^/" + path + "/([0-9.:]+)"]["GET"] = [&](std::shared_ptr<HttpServer::Response> response, std::shared_ptr<HttpServer::Request> request) {
        std::string key = Utility::split(request->path,'/')[2];
        T* item = container.getById(key);

        std::stringstream ss;
        if (item == nullptr) {
            Json::Value root;
            Json::StyledWriter styledWriter;
            root["success"] = false;
            root["message"] = "Not found";
            ss << styledWriter.write(root);
            *response   << "HTTP/1.1 404 Not Found\r\n"
                        << "Content-Length: " << ss.str().length() << "\r\n"
                        << "\r\n"
                        << ss.str();
        } else {
            Json::Value root;
            root["success"] = true;
            root["item"] = item->json();
            Json::StyledWriter styledWriter;
            ss << styledWriter.write(root);
            *response   << "HTTP/1.1 200 OK\r\n"
                        << "Access-Control-Allow-Origin: *\r\n"
                        << "Content-Length: " << ss.str().length() << "\r\n"
                        << "\r\n"
                        << ss.str();
        }
    };

    server.resource["^/" + path + "$"]["OPTIONS"] = [&](std::shared_ptr<HttpServer::Response> response, const std::shared_ptr<HttpServer::Request>& /*request*/) {
        std::string str = "OK";
        *response   << "HTTP/1.1 200 OK\r\n"
                    << "Access-Control-Allow-Methods: GET POST OPTIONS\r\n"
                    << "Access-Control-Allow-Headers: content-type, x-requested-with\r\n"
                    << "Access-Control-Allow-Origin: *\r\n"
                    << "Content-Length: " << str.length() << "\r\n"
                    << "\r\n"
                    << str;
    };

    server.resource["^/" + path + "$"]["GET"] = [&](std::shared_ptr<HttpServer::Response> response, std::shared_ptr<HttpServer::Request> request) {
        Json::Value req;
        std::stringstream in;
        std::string body = request->content.string();
        if (!body.empty()) {
            in << body;
            in >> req;
        }

        std::stringstream ss;
        {
            Json::Value root;
            root["success"] = true;
            Json::Value nested = Json::arrayValue;
            unsigned int totalCount = 0;
            unsigned int maxResults = 100;
            unsigned int start = 0;

            auto query_fields = request->parse_query_string();
            {
                auto umit = query_fields.find("limit");
                if (umit != query_fields.end()) {
                    maxResults = std::stoi(query_fields.find("limit")->second);
                }
            }
            {
                auto umit = query_fields.find("start");
                if (umit != query_fields.end()) {
                    start = std::stoi(query_fields.find("start")->second);
                }
            }
            // e.g. [{"property":"event_id","direction":"DESC"}]
            S sorter;
            {
                auto umit = query_fields.find("sort");
                if (umit != query_fields.end()) {
                    std::string sort = query_fields.find("sort")->second;
                    std::cout << sort << std::endl;

                    Json::Value jsonSort;
                    Json::Reader reader;
                    if (reader.parse( sort, jsonSort )) {
                        sorter = S(jsonSort);
                    }
                }
            }

            F filter;
            {
                auto umit = query_fields.find("filter");
                if (umit != query_fields.end()) {
                    std::string filterString = query_fields.find("filter")->second;
                    std::cout << filterString << std::endl;

                    Json::Value jsonFilter;
                    Json::Reader reader;
                    if (reader.parse( filterString, jsonFilter )) {
                        filter = F(jsonFilter);
                    }
                }
            }

            std::vector<T*> itemsCopy = container.toVector(sorter, filter);

            for (const T* item: itemsCopy) {
                if ((totalCount >= start) && (totalCount <= start+maxResults) && (filter.matches(*item))) {
                    nested.append(item->json());
                }
                totalCount++;
            }

            root["items"] = nested;
            root["total_count"] = totalCount;
            Json::StyledWriter styledWriter;
            ss << styledWriter.write(root);
            *response   << "HTTP/1.1 200 OK\r\n"
                        << "Access-Control-Allow-Origin: *\r\n"
                        << "Content-Length: " << ss.str().length() << "\r\n"
                        << "\r\n"
                        << ss.str();
        }
    };
}


void WebServer::init() {

    HttpServer server;
    server.config.port = 8080;
    addResource<Data::Market,DataModel<Data::Market>,Data::MarketFilter, Data::MarketSorter> (server, "market", bd.marketModel());
    addResource<Data::Runner,DataModel<Data::Runner>,Data::Filter, Data::Sorter> (server, "runner", bd.runnerModel());
    addResource<Data::Event,DataModel<Data::Event>,Data::Filter, Data::Sorter> (server, "event", bd.eventModel());
    addResource<Data::Race,DataModel<Data::Race>,Data::Filter, Data::Sorter> (server, "race", bd.raceModel());
    addResource<Data::Group,DataModel<Data::Group>,Data::Filter, Data::Sorter> (server, "group", bd.groupModel());
    addResource<Data::EventType,DataModel<Data::EventType>,Data::Filter, Data::Sorter> (server, "eventtype", bd.eventTypeModel());
    addResource<Data::Order,DataModel<Data::Order>,Data::Filter, Data::Sorter> (server, "order", bd.orderModel());
    addResource<Data::MarketRunner,DataModel<Data::MarketRunner>,Data::Filter, Data::Sorter> (server, "marketrunner", bd.marketRunnerModel());

    std::thread server_thread([&server]() {
        // Start server
        std::cout << "Starting WebServer" << std::endl;
        server.start();
    });

    server_thread.join();

}

WebServer::WebServer(DataModels &bd) : bd(bd) {

}
