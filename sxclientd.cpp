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

    DataModels dataModels;
    NavigationLoader navigationLoader(dataModels);
    APIClient api;
    navigationLoader.init();

    std::thread taskThread = std::thread(TaskManager(dataModels, api));

    WebServer ws(dataModels);
    ws.init();

    Application::state = Application::State::READY;

    return 0;
}