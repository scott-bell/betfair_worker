//
// Created by scott on 16/01/2020.
//

#include "NavigationLoader.h"
#include "BetfairData.h"
#include "BetfairAPI.h"
#include "WebServer.h"
#include "TaskManager.h"
#include "Application.h"
#include <thread>

int main() {

    BetfairData bd;
    NavigationLoader nl(bd);
    BetfairAPI api;
    nl.init();

    std::thread taskThread = std::thread(TaskManager(bd,api));

    WebServer ws(bd);
    ws.init();

    Application::state = Application::State::READY;

    return 0;
}