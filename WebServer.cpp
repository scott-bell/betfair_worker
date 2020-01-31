//
// Created by scott on 31/01/2020.
//

#include <jsoncpp/json/json.h>
#include "WebServer.h"
#include "Utility.h"

void WebServer::init() {

    HttpServer server;
    server.config.port = 8080;

    server.resource["^/market/1.([0-9]+)"]["GET"] = [&](std::shared_ptr<HttpServer::Response> response, std::shared_ptr<HttpServer::Request> request) {
        std::string key = Utility::split(request->path,'/')[2];
        BetfairMarket* item = bd.getBetfairMarket(key);

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

    std::thread server_thread([&server]() {
        // Start server
        server.start();
    });

    server_thread.join();

}

WebServer::WebServer(BetfairData &bd) : bd(bd) {

}
