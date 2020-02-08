//
// Created by scott on 31/01/2020.
//

#include <jsoncpp/json/json.h>
#include "WebServer.h"
#include "Utility.h"

template <typename T, typename C>
void WebServer::addResource(HttpServer& server, const std::string& path, C& container) {
    server.resource["^/" + path + "/([0-9.]+)"]["GET"] = [&](std::shared_ptr<HttpServer::Response> response, std::shared_ptr<HttpServer::Request> request) {
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
}

void WebServer::init() {

    HttpServer server;
    server.config.port = 8080;
    addResource<BetfairMarket,DataModel<BetfairMarket>> (server, "market", bd.marketModel());
    addResource<BetfairRunner,DataModel<BetfairRunner>> (server, "runner", bd.runnerModel());
    addResource<BetfairEvent,DataModel<BetfairEvent>> (server, "event", bd.eventModel());
    addResource<BetfairRace,DataModel<BetfairRace>> (server, "race", bd.raceModel());
    addResource<BetfairGroup,DataModel<BetfairGroup>> (server, "group", bd.groupModel());
    addResource<BetfairEventType,DataModel<BetfairEventType>> (server, "eventtype", bd.eventTypeModel());
    addResource<BetfairOrder,DataModel<BetfairOrder>> (server, "order", bd.orderModel());

    std::thread server_thread([&server]() {
        // Start server
        std::cout << "Starting WebServer" << std::endl;
        server.start();
    });

    server_thread.join();

}

WebServer::WebServer(BetfairData &bd) : bd(bd) {

}
