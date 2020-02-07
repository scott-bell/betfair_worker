//
// Created by scott on 31/01/2020.
//

#ifndef BETFAIR_WORKER_WEBSERVER_H
#define BETFAIR_WORKER_WEBSERVER_H

#include <3rd-party/SimpleWeb/server_http.hpp>
#include "BetfairData.h"

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;

class WebServer {
    BetfairData& bd;
public:
    explicit WebServer(BetfairData& bd);
    void init();

    template <typename T, typename C>
    void addResource(HttpServer& server, const std::string &path, C& container);
};


#endif //BETFAIR_WORKER_WEBSERVER_H
