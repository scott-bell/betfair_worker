//
// Created by scott on 31/01/2020.
//

#ifndef SXCLIENT_TASKMANAGER_H
#define SXCLIENT_TASKMANAGER_H


#include "DataModels.h"
#include "APIClient.h"

class TaskManager {
    DataModels& m_dataModels;
    APIClient& m_api;
    std::set<std::string> m_detailedMarketIds;
    void getMarketCatalogue(const std::set<std::string>& marketIds);
    void getMarketBook(const std::set<std::string>& marketIds);
    void getOrders();
public:
    TaskManager(DataModels& bd, APIClient& api);
    void init();
    void operator() ();

};


#endif //SXCLIENT_TASKMANAGER_H
