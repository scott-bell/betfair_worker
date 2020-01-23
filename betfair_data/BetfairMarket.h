//
// Created by scott on 16/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRMARKET_H
#define BETFAIR_WORKER_BETFAIRMARKET_H


#include <string>
#include <optional>
#include "BetfairObject.h"

class BetfairMarket : public BetfairObject {
    std::string m_exchange_id;
    std::string m_market_start_time;
    std::string m_market_type;
    std::optional<int> m_number_of_winners;
    std::string m_name;

    // Optional description data below
    std::optional<bool> m_persistenceEnabled;
    std::optional<bool> m_bspMarket;
    std::optional<std::string> m_marketTime;
    std::optional<std::string> m_suspendTime;
    std::optional<std::string> m_settleTime;
    std::optional<bool> m_turnInPlayEnabled;
    std::optional<bool> m_marketType;
    std::optional<bool> m_regulator;
    std::optional<double> m_marketBaseRate;
    std::optional<bool> m_discountAllowed;
    std::optional<std::string> m_wallet;
    std::optional<std::string> m_rules;
    std::optional<bool> m_rulesHasDate;
    std::optional<double> m_eachWayDivisor;
    std::optional<std::string> m_clarifications;
    std::optional<std::string> m_raceType;

    //MarketBettingType m_bettingType; // TODO: https://docs.developer.betfair.com/display/1smk3cen4v3lu3yomq5qye0ni/Betting+Enums#BettingEnums-MarketBettingType
    //MarketLineRangeInfo m_lineRangeInfo; // TODO: https://docs.developer.betfair.com/display/1smk3cen4v3lu3yomq5qye0ni/Betting+Type+Definitions#BettingTypeDefinitions-MarketLineRangeInfo
    //PriceLadderDescription m_PriceLadderDescription; // TODO


public:
    BetfairMarket(std::string id, std::string exchange_id, std::string market_start_time,
                  std::string market_type, std::optional<int> number_of_winners, std::string name);
    BetfairMarket() = delete;
    const std::string& get_exchange_id() const;
    const std::string& get_market_start_time() const;
    const std::string& get_market_type() const;
    std::optional<int> get_number_of_winners() const;
    const std::string& get_name() const;
};

#endif //BETFAIR_WORKER_BETFAIRMARKET_H
