//
// Created by scott on 31/01/2020.
//

#ifndef BETFAIR_WORKER_TASKMANAGER_H
#define BETFAIR_WORKER_TASKMANAGER_H


#include "BetfairData.h"
#include "BetfairAPI.h"

class TaskManager {
    BetfairData& bd;
    BetfairAPI& api;
public:
    explicit TaskManager(BetfairData& bd, BetfairAPI& api);
    void init();

};


#endif //BETFAIR_WORKER_TASKMANAGER_H
