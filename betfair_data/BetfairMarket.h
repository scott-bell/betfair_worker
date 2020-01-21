//
// Created by scott on 16/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRMARKET_H
#define BETFAIR_WORKER_BETFAIRMARKET_H


#include <string>
#include "BetfairObject.h"

class BetfairMarket : public BetfairObject {
    std::string m_exchange_id;
    std::string m_market_start_time;
    std::string m_market_type;
    int m_number_of_winners;
    std::string m_name;
public:
    BetfairMarket(std::string id, std::string exchange_id, std::string market_start_time,
                  std::string market_type, int number_of_winners, std::string name);
    BetfairMarket() = delete;
    const std::string& get_exchange_id() const;
    const std::string& get_market_start_time() const;
    const std::string& get_market_type() const;
    int get_number_of_winners() const;
    const std::string& get_name() const;
};

#endif //BETFAIR_WORKER_BETFAIRMARKET_H
