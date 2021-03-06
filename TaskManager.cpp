//
// Created by scott on 31/01/2020.
//

#include "TaskManager.h"
#include "Application.h"
#include <thread>

TaskManager::TaskManager(DataModels &bd, APIClient& api) : m_dataModels(bd), m_api(api) {

}

void TaskManager::operator() (){
    std::cout << "Started task manager thread";
    init();
}

void TaskManager::init() {

    while (Application::state != Application::State::STOPPING)
    {
        std::set<std::string> marketIds(m_detailedMarketIds);
        for (const auto& i : m_dataModels.marketModel().items()) {
            if ((i.second.marketType() == "MATCH_ODDS") && (!i.second.bettingType().has_value())) {
                marketIds.emplace(i.second.id());
            }
        }

        std::set<std::string> marketIdsSummary;
        for (const auto& i : marketIds) {
            if (marketIdsSummary.size() < 200) {
                marketIdsSummary.emplace(i);
            } else {
                getMarketCatalogue(marketIdsSummary);
                marketIdsSummary.clear();
            }
        }
        if (!marketIdsSummary.empty()) {
            getMarketCatalogue(marketIdsSummary);
            marketIdsSummary.clear();
        }

        getMarketBook(m_detailedMarketIds);

        getOrders();

        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}

void TaskManager::getOrders() {
    std::vector<std::string> existingIds;
    std::vector<std::string> seenIds;
    for (const auto& item : m_dataModels.orderModel().items()) {
        if (item.second.status() != "EXECUTION_COMPLETE")
            existingIds.push_back(item.second.id());
    }
    {
        API::CurrentOrderSummaryReport report;
        report = m_api.listCurrentOrders(std::nullopt, std::nullopt, "ALL", std::nullopt, std::nullopt, std::nullopt,
                                         "BY_PLACE_TIME", "EARLIEST_TO_LATEST", 0, 1000);
        for (const API::CurrentOrderSummary& summary : report.currentOrders) {
            Data::Order *obj = m_dataModels.orderModel().getById(summary.betId);
            seenIds.push_back(summary.betId);
            if (obj == nullptr) {
                Data::Market* market = m_dataModels.marketModel().getById(summary.marketId);
                Data::Runner* runner = m_dataModels.runnerModel().getById(std::to_string(summary.selectionId));
                if (market == nullptr)
                    std::cout << "Cannot find market with id " << summary.marketId << std::endl;
                else if (runner == nullptr) {
                    std::cout << "Order " << summary.betId << ": Cannot find runner with id " << std::to_string(summary.selectionId) << " for market " << summary.marketId << std::endl;
                    m_detailedMarketIds.emplace(summary.marketId);
                }
                else {
                    auto o = Data::Order(
                            summary.betId,
                            market,
                            runner,
                            summary.handicap,
                            summary.priceSize.price,
                            summary.priceSize.size,
                            summary.bspLiability,
                            summary.side,
                            summary.status,
                            summary.persistenceType,
                            summary.orderType,
                            summary.placedDate,
                            summary.matchedDate,
                            summary.sizeMatched.has_value() ? summary.sizeMatched.value() : 0.0,
                            summary.sizeRemaining.has_value() ? summary.sizeRemaining.value() : 0.0,
                            summary.sizeLapsed.has_value() ? summary.sizeLapsed.value() : 0.0,
                            summary.sizeCancelled.has_value() ? summary.sizeCancelled.value() : 0.0,
                            summary.sizeVoided.has_value() ? summary.sizeVoided.value() : 0.0,
                            summary.regulatorAuthCode,
                            summary.regulatorCode,
                            summary.customerOrderRef,
                            summary.customerStrategyRef);
                    m_dataModels.orderModel().add(o);
                }
            } else {
                obj->status(summary.status);
                obj->persistenceType(summary.persistenceType);
                obj->sizeCancelled(summary.sizeCancelled.value());
                obj->sizeRemaining(summary.sizeRemaining.value());
                obj->sizeMatched(summary.sizeMatched.value());
                obj->sizeLapsed(summary.sizeLapsed.value());
                obj->sizeVoided(summary.sizeVoided.value());
            }
        }
    }
    std::vector<std::string> missingOrderIds;
    std::sort(existingIds.begin(), existingIds.end());
    std::sort(seenIds.begin(), seenIds.end());
    std::set_difference(
        existingIds.begin(), existingIds.end(),
        seenIds.begin(), seenIds.end(),
        std::back_inserter(missingOrderIds)
    );
    if (!missingOrderIds.empty())
    {
        for (const std::string& id : missingOrderIds)
        {
            Data::Order *obj = m_dataModels.orderModel().getById(id);
            obj->sizeCancelled(obj->sizeRemaining());
            obj->sizeRemaining(0.0);
            obj->status("EXECUTION_COMPLETE");
        }
    }
}

void TaskManager::getMarketCatalogue(const std::set<std::string>& marketIds) {
    {
        std::cout << "listMarketCatalogue" << std::endl;
        API::MarketFilter filter(marketIds);
        std::set<std::string> projection = {"MARKET_START_TIME", "MARKET_DESCRIPTION", "RUNNER_DESCRIPTION"};
        std::forward_list<API::MarketCatalogue> items = m_api.listMarketCatalogue(filter, projection, "FIRST_TO_START", 1000,
                                                                                  "en");

        for (API::MarketCatalogue &item : items) {
            Data::Market *obj = m_dataModels.marketModel().getById(item.marketId);
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
            if (item.runners.has_value())
            {
                for (const API::RunnerCatalog& rg : item.runners.value()) {
                    Data::Runner *runnerObj = m_dataModels.runnerModel().getById(std::to_string(rg.selectionId));
                    if (runnerObj == nullptr) {
                        runnerObj = &(m_dataModels.runnerModel().add(Data::Runner(std::to_string(rg.selectionId), rg.runnerName)));
                    }
                    std::string mrId = obj->id() + ":" + runnerObj->id();
                    Data::MarketRunner *marketRunnerObj = m_dataModels.marketRunnerModel().getById(mrId);
                    if (marketRunnerObj == nullptr) {
                        marketRunnerObj = &(m_dataModels.marketRunnerModel().add(Data::MarketRunner(mrId, *runnerObj, rg.handicap, rg.sortPriority)));
                        obj->addMarketRunner(marketRunnerObj);
                    }
                }
            }

        }
    }


}

void TaskManager::getMarketBook(const std::set<std::string> &marketIds) {
    {
        std::cout << "listMarketBook" << std::endl;
        if (marketIds.empty()) { return; }

        std::forward_list<std::string> marketIds2;
        for (auto m :  marketIds) {
            marketIds2.push_front(m);
        }
        std::vector<std::string> v = {"EX_ALL_OFFERS", "EX_TRADED"};
        API::PriceProjection projection = {v, std::nullopt, false, false};
        std::forward_list<API::MarketBook> result = m_api.listMarketBook(marketIds2, projection, "ALL", "NO_ROLLUP", false,
                                                                         false, std::nullopt, "USD", "en", std::nullopt,
                                                                         std::nullopt);

        for (API::MarketBook &b : result) {
            Data::Market *bfItem = m_dataModels.marketModel().getById(b.marketId);
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
                if (b.runners.has_value()) {
                    for (const API::Runner& runner : b.runners.value()) {
                        Data::Runner *runnerObj = m_dataModels.runnerModel().getById(std::to_string(runner.selectionId));
                        if (runnerObj != nullptr) {
                            std::string mrId = bfItem->id() + ":" + runnerObj->id();
                            Data::MarketRunner *marketRunnerObj = m_dataModels.marketRunnerModel().getById(mrId);
                            if (marketRunnerObj != nullptr) {
                                marketRunnerObj->status(runner.status);
                                marketRunnerObj->handicap(runner.handicap);
                                marketRunnerObj->adjustmentFactor(runner.adjustmentFactor);
                                if (runner.lastPriceTraded.has_value())
                                    marketRunnerObj->lastPriceTraded(runner.lastPriceTraded.value());
                                if (runner.totalMatched.has_value())
                                    marketRunnerObj->totalMatched(runner.totalMatched.value());
                                if (runner.removalDate.has_value())
                                    marketRunnerObj->removalDate(runner.removalDate.value());
                                if (runner.ex.has_value()) {
                                    if (runner.ex.value().availableToBack.has_value()) {
                                        std::vector<std::tuple<double,double>> bp;
                                        std::vector<std::tuple<double,double>> lp;
                                        std::vector<std::tuple<double,double>> tp;
                                        for (const API::PriceSize& pz : runner.ex.value().availableToBack.value()) {
                                            std::tuple<double,double> pzt = {pz.price,pz.size};
                                            bp.push_back(pzt);
                                        }
                                        for (const API::PriceSize& pz : runner.ex.value().availableToLay.value()) {
                                            std::tuple<double,double> pzt = {pz.price,pz.size};
                                            lp.push_back(pzt);
                                        }
                                        for (const API::PriceSize& pz : runner.ex.value().tradedVolume.value()) {
                                            std::tuple<double,double> pzt = {pz.price,pz.size};
                                            tp.push_back(pzt);
                                        }
                                        marketRunnerObj->backPrices(bp);
                                        marketRunnerObj->layPrices(lp);
                                        marketRunnerObj->tradedPrices(tp);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}