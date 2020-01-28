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

    /*
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

    PlaceExecutionReport per = api.placeOrders("1.167886771", instructions, "Test1", std::nullopt, "TEST1", false);*/


    /*std::vector<std::string> priceData = {"SP_AVAILABLE", "EX_TRADED", "EX_ALL_OFFERS", "EX_TRADED"};
    std::vector<std::string> strategyRefs = {};
    std::vector<std::string> betIds = {};
    ExBestOffersOverrides exBestOffersOverrides { 10, "STAKE", 100, 2.5, 5 };
    PriceProjection priceProjection{ priceData, std::nullopt, true, true };

    std::vector<MarketBook> v = api.listMarketBook({"1.167920782"}, priceProjection, "ALL", "NO_ROLLUP", true, false,std::nullopt,"GBP","en",std::nullopt, std::nullopt);*/

    CurrentOrderSummaryReport sum = api.listCurrentOrders(std::nullopt, std::nullopt, "ALL", std::nullopt, std::nullopt, std::nullopt, "BY_PLACE_TIME", "EARLIEST_TO_LATEST", 0, 100);

    std::cout << "Goodbye." << std::endl;


    return 0;
}