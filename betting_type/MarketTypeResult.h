//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_MARKETTYPERESULT_H
#define BETFAIR_WORKER_MARKETTYPERESULT_H


#include <string>
#include <optional>

struct MarketTypeResult {
    std::optional<std::string> marketType;
    std::optional<int> marketCount;
};


#endif //BETFAIR_WORKER_MARKETTYPERESULT_H
