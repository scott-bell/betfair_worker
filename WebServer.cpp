//
// Created by scott on 31/01/2020.
//

#include <jsoncpp/json/json.h>
#include <data_models/MarketFilter.h>
#include "WebServer.h"
#include "Utility.h"

template <typename T, typename C, typename F>
void WebServer::addResource(HttpServer& server, const std::string& path, C& container) {
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
                        << "Content-Length: " << ss.str().length() << "\r\n"
                        << "\r\n"
                        << ss.str();
        }
    };

    server.resource["^/" + path + "$"]["GET"] = [&](std::shared_ptr<HttpServer::Response> response, std::shared_ptr<HttpServer::Request> request) {
        const auto& items = container.items();

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
            int totalCount = 0;
            unsigned int maxResults = 100;
            F filter;


            if (req.isMember("filter")) {
                filter = F(req["filter"]);
            }
            if (req.isMember("max_results")) {
                maxResults = req["max_results"].asInt();
            }

            for (auto item: items) {
                totalCount++;
                if (nested.size() < maxResults) {
                    if (filter.match(item.second))
                        nested.append(item.second.json());
                }
            }
            root["items"] = nested;
            root["total_count"] = totalCount;
            Json::StyledWriter styledWriter;
            ss << styledWriter.write(root);
            *response   << "HTTP/1.1 200 OK\r\n"
                        << "Content-Length: " << ss.str().length() << "\r\n"
                        << "\r\n"
                        << ss.str();
        }
    };
}


void WebServer::init() {

    HttpServer server;
    server.config.port = 8080;
    addResource<Data::Market,DataModel<Data::Market>,MarketFilter> (server, "market", bd.marketModel());
    addResource<Data::Runner,DataModel<Data::Runner>,Filter> (server, "runner", bd.runnerModel());
    addResource<Data::Event,DataModel<Data::Event>,Filter> (server, "event", bd.eventModel());
    addResource<Data::Race,DataModel<Data::Race>,Filter> (server, "race", bd.raceModel());
    addResource<Data::Group,DataModel<Data::Group>,Filter> (server, "group", bd.groupModel());
    addResource<Data::EventType,DataModel<Data::EventType>,Filter> (server, "eventtype", bd.eventTypeModel());
    addResource<Data::Order,DataModel<Data::Order>,Filter> (server, "order", bd.orderModel());
    addResource<Data::MarketRunner,DataModel<Data::MarketRunner>,Filter> (server, "marketrunner", bd.marketRunnerModel());

    std::thread server_thread([&server]() {
        // Start server
        std::cout << "Starting WebServer" << std::endl;
        server.start();
    });

    server_thread.join();

}

WebServer::WebServer(DataModels &bd) : bd(bd) {

}
