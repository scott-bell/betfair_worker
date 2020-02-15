//
// Created by scott on 31/01/2020.
//

#ifndef SXCLIENT_WEBSERVER_H
#define SXCLIENT_WEBSERVER_H

#include <3rd-party/SimpleWeb/server_http.hpp>
#include "DataModels.h"

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;

class WebServer {
    DataModels& bd;
public:
    explicit WebServer(DataModels& bd);
    void init();

    template <typename T, typename C>
    void addResource(HttpServer& server, const std::string &path, C& container);
};


#endif //SXCLIENT_WEBSERVER_H
