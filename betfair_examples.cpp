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

    std::vector<PlaceInstruction> instructions;

    // Limit order
    {
        LimitOrder limitOrder(2.1, 12, "LAPSE", std::nullopt, std::nullopt, std::nullopt, std::nullopt);
        PlaceInstruction instruction("LIMIT", 21029911, std::nullopt, "BACK", limitOrder, std::nullopt, std::nullopt, "Test123");
        instructions.push_back(instruction);
    }

    PlaceExecutionReport per = api.placeOrders("1.167886771", instructions, "Test1", std::nullopt, "TEST1", false);

    std::cout << "Goodbye." << std::endl;


    return 0;
}