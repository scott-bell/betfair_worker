//
// Created by scott on 31/01/2020.
//

#include "TaskManager.h"

TaskManager::TaskManager(BetfairData &bd, BetfairAPI& api) : bd(bd), api(api) {



}

void TaskManager::init() {


    std::cout << "listMarketCatalogue" << std::endl;
    MarketFilter filter({"1.167951761"});
    std::set<std::string> projection = {"MARKET_START_TIME","MARKET_DESCRIPTION", "RUNNER_DESCRIPTION"};
    std::forward_list<MarketCatalogue> items = api.listMarketCatalogue(filter,projection,"FIRST_TO_START",1000,"en");

    for (MarketCatalogue& item : items) {
        BetfairMarket* obj = bd.getBetfairMarket(item.marketId);
        obj->name(item.marketName);
        if (item.marketStartTime.has_value())
            obj->startTime(item.marketStartTime.value());
        if (item.description.has_value()) {
            obj->persistenceEnabled(item.description.value().persistenceEnabled);
            obj->bspMarket(item.description.value().bspMarket);
            obj->suspendTime(item.description.value().suspendTime);
            if (item.description.value().settleTime.has_value())
                obj->settleTime(item.description.value().settleTime.value());
            obj->bettingType(item.description.value().bettingType);
            obj->turnInPlayEnabled(item.description.value().turnInPlayEnabled);
            obj->marketType(item.description.value().marketType);
            obj->regulator(item.description.value().regulator);
            obj->discountAllowed(item.description.value().discountAllowed);
            if (item.description.value().wallet.has_value())
                obj->wallet(item.description.value().wallet.value());
            if (item.description.value().rules.has_value())
                obj->rules(item.description.value().rules.value());
            if (item.description.value().rulesHasDate.has_value())
                obj->rulesHasDate(item.description.value().rulesHasDate.value());
        }
    }


    std::cout << "listMarketBook" << std::endl;

    std::forward_list<std::string> marketIds = {"1.167951761"};
    std::forward_list<MarketBook> result = api.listMarketBook(marketIds);

    for (MarketBook& b : result) {
        BetfairMarket* bfItem = bd.getBetfairMarket(b.marketId);
        if (bfItem != nullptr) {
            bfItem->isMarketDateDelayed(b.isMarketDataDelayed);
            if (b.status.has_value())
                bfItem->status(b.status.value());
            if (b.betDelay.has_value())
                bfItem->betDelay(b.betDelay.value());
            if (b.bspReconciled.has_value())
                bfItem->bspReconciled(b.bspReconciled.value());
            if (b.complete.has_value())
                bfItem->complete(b.complete.value());
            if (b.inplay.has_value())
                bfItem->inplay(b.inplay.value());
            if (b.numberOfWinners.has_value())
                bfItem->numberOfWinners(b.numberOfWinners.value());
            if (b.numberOfRunners.has_value())
                bfItem->numberOfRunners(b.numberOfRunners.value());
            if (b.numberOfActiveRunners.has_value())
                bfItem->numberOfActiveRunners(b.numberOfActiveRunners.value());
            if (b.lastMatchTime.has_value())
                bfItem->lastMatchTime(b.lastMatchTime.value());
            if (b.totalMatched.has_value())
                bfItem->totalMatched(b.totalMatched.value());
            if (b.totalAvailable.has_value())
                bfItem->totalAvailable(b.totalAvailable.value());
            if (b.crossMatching.has_value())
                bfItem->crossMatching(b.crossMatching.value());
            if (b.runnersVoidable.has_value())
                bfItem->runnersVoidable(b.runnersVoidable.value());
            if (b.version.has_value())
                bfItem->version(b.version.value());
        }
    }




}
