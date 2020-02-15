//
// Created by scott on 16/01/2020.
//

#include "NavigationLoader.h"
#include "DataModels.h"
#include "APIClient.h"
#include "WebServer.h"
#include "TaskManager.h"
#include "Application.h"
#include <thread>

int main() {

    DataModels bd;
    NavigationLoader nl(bd);
    APIClient api;
    nl.init();

    std::thread taskThread = std::thread(TaskManager(bd,api));

    WebServer ws(bd);
    ws.init();

    Application::state = Application::State::READY;

    return 0;
}