//
// Created by scott on 16/01/2020.
//

#include <betting_type/MarketFilter.h>
#include "NavigationLoader.h"
#include "BetfairData.h"
#include "APILoader.h"
#include <betting_type/MarketCatalogue.h>

int main() {

    BetfairData bd;
    NavigationLoader nl(bd);
    APILoader api;


    MarketFilter filter{};
    filter.m_marketIds = { "1.167829691"};
    std::set<std::string> marketProjection = {"COMPETITION", "EVENT", "EVENT_TYPE", "MARKET_START_TIME", "MARKET_DESCRIPTION", "RUNNER_DESCRIPTION", "RUNNER_METADATA"};
    std::vector<MarketCatalogue> catalogue = api.listMarketCatalogue(filter, marketProjection, "FIRST_TO_START", 100, "en");

    std::cout << "Goodbye." << std::endl;


    return 0;
}