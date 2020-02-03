//
// Created by scott on 03/02/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRRUNNER_H
#define BETFAIR_WORKER_BETFAIRRUNNER_H


#include <jsoncpp/json/json.h>
#include "BetfairObject.h"

class BetfairRunner  : public BetfairObject {
    std::string m_name;
public:
    Json::Value json();
    BetfairRunner(std::string id, std::string name);
};


#endif //BETFAIR_WORKER_BETFAIRRUNNER_H
