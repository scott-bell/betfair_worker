//
// Created by scott on 30/03/2020.
//

#include "MarketSorter.h"

#include <utility>
#include "Market.h"

namespace Data {

    MarketSorter::MarketSorter(Json::Value json) : Sorter(json), json(json) {
    }

    bool MarketSorter::compare(const DataObject &lhs, const DataObject &rhs) const {
        const Data::Market* l = (Data::Market*)(&lhs);
        const Data::Market* r = (Data::Market*)(&rhs);

        for (const Json::Value &index : json) {
            bool desc = index["direction"] == "DESC";
            if (index["property"] == "name") {
                if (desc)
                    return l->name() > r->name();
                else
                    return l->name() < r->name();
            }
            else if (index["property"] == "start_time") {
                if (desc)
                    return l->startTime() > r->startTime();
                else
                    return l->startTime() < r->startTime();
            }
            else if (index["property"] == "type") {
                if (desc)
                    return l->marketType() > r->marketType();
                else
                    return l->marketType() < r->marketType();
            }
            else if (index["property"] == "number_of_winners") {
                if (desc)
                    return l->numberOfWinners() > r->numberOfWinners();
                else
                    return l->numberOfWinners() < r->numberOfWinners();
            }
            else if (index["property"] == "exchange_id") {
                if (desc)
                    return l->exchangeId() > r->exchangeId();
                else
                    return l->exchangeId() < r->exchangeId();
            }
            else if ((index["property"] == "event_id") && (l->parentEvent() != nullptr) && (r->parentEvent() != nullptr)) {
                if (desc)
                    return l->parentEvent()->id() > r->parentEvent()->id();
                else
                    return l->parentEvent()->id() < r->parentEvent()->id();
            }
            else if ((index["property"] == "event_name") && (l->parentEvent() != nullptr) && (r->parentEvent() != nullptr)) {
                if (desc)
                    return l->parentEvent()->get_name() > r->parentEvent()->get_name();
                else
                    return l->parentEvent()->get_name() < r->parentEvent()->get_name();
            }
            else if ((index["property"] == "race_id" ) && (l->parentRace() != nullptr) && (r->parentRace() != nullptr)) {
                if (desc)
                    return l->parentRace()->id() > r->parentRace()->id();
                else
                    return l->parentRace()->id() < r->parentRace()->id();
            }
            else if ((index["property"] == "race_name") && (l->parentRace() != nullptr) && (r->parentRace() != nullptr)) {
                if (desc)
                    return l->parentRace()->get_name() > r->parentRace()->get_name();
                else
                    return l->parentRace()->get_name() < r->parentRace()->get_name();
            }
            else if (index["property"] == "persistence_enabled") {
                if (desc)
                    return l->persistenceEnabled() > r->persistenceEnabled();
                else
                    return l->persistenceEnabled() < r->persistenceEnabled();
            }
            else if (index["property"] == "bsp_market") {
                if (desc)
                    return l->bspMarket() > r->bspMarket();
                else
                    return l->bspMarket() < r->bspMarket();
            }
            else if (index["property"] == "suspend_time") {
                if (desc)
                    return l->suspendTime() > r->suspendTime();
                else
                    return l->suspendTime() < r->suspendTime();
            }
            else if (index["property"] == "settle_time") {
                if (desc)
                    return l->settleTime() > r->settleTime();
                else
                    return l->settleTime() < r->settleTime();
            }
            else if (index["property"] == "status") {
                if (desc)
                    return l->status() > r->status();
                else
                    return l->status() < r->status();
            }
            else if (index["property"] == "betting_type") {
                if (desc)
                    return l->bettingType() > r->bettingType();
                else
                    return l->bettingType() < r->bettingType();
            }
            else if (index["property"] == "turn_in_play_enabled") {
                if (desc)
                    return l->turnInPlayEnabled() > r->turnInPlayEnabled();
                else
                    return l->turnInPlayEnabled() < r->turnInPlayEnabled();
            }
            else if (index["property"] == "regulator") {
                if (desc)
                    return l->regulator() > r->regulator();
                else
                    return l->regulator() < r->regulator();
            }
            else if (index["property"] == "market_base_rate") {
                if (desc)
                    return l->marketBaseRate() > r->marketBaseRate();
                else
                    return l->marketBaseRate() < r->marketBaseRate();
            }
            else if (index["property"] == "discount_allowed") {
                if (desc)
                    return l->discountAllowed() > r->discountAllowed();
                else
                    return l->discountAllowed() < r->discountAllowed();
            }
            else if (index["property"] == "wallet") {
                if (desc)
                    return l->wallet() > r->wallet();
                else
                    return l->wallet() < r->wallet();
            }
            else if (index["property"] == "each_way_divisor") {
                if (desc)
                    return l->eachWayDivisor() > r->eachWayDivisor();
                else
                    return l->eachWayDivisor() < r->eachWayDivisor();
            }
            else if (index["property"] == "clarifications") {
                if (desc)
                    return l->clarifications() > r->clarifications();
                else
                    return l->clarifications() < r->clarifications();
            }
            else if (index["property"] == "race_type") {
                if (desc)
                    return l->raceType() > r->raceType();
                else
                    return l->raceType() < r->raceType();
            }
            else if (index["property"] == "is_market_data_delayed") {
                if (desc)
                    return l->isMarketDataDelayed() > r->isMarketDataDelayed();
                else
                    return l->isMarketDataDelayed() < r->isMarketDataDelayed();
            }
            else if (index["property"] == "bet_delay") {
                if (desc)
                    return l->betDelay() > r->betDelay();
                else
                    return l->betDelay() < r->betDelay();
            }
            else if (index["property"] == "bsp_reconciled") {
                if (desc)
                    return l->bspReconciled() > r->bspReconciled();
                else
                    return l->bspReconciled() < r->bspReconciled();
            }
            else if (index["property"] == "complete") {
                if (desc)
                    return l->complete() > r->complete();
                else
                    return l->complete() < r->complete();
            }
            else if (index["property"] == "inplay") {
                if (desc)
                    return l->inplay() > r->inplay();
                else
                    return l->inplay() < r->inplay();
            }
            else if (index["property"] == "number_of_runners") {
                if (desc)
                    return l->numberOfRunners() > r->numberOfRunners();
                else
                    return l->numberOfRunners() < r->numberOfRunners();
            }
            else if (index["property"] == "number_of_active_runners") {
                if (desc)
                    return l->numberOfActiveRunners() > r->numberOfActiveRunners();
                else
                    return l->numberOfActiveRunners() < r->numberOfActiveRunners();
            }
            else if (index["property"] == "last_match_time") {
                if (desc)
                    return l->lastMatchTime() > r->lastMatchTime();
                else
                    return l->lastMatchTime() < r->lastMatchTime();
            }
            else if (index["property"] == "total_matched") {
                if (desc)
                    return l->totalMatched() > r->totalMatched();
                else
                    return l->totalMatched() < r->totalMatched();
            }
            else if (index["property"] == "total_available") {
                if (desc)
                    return l->totalAvailable() > r->totalAvailable();
                else
                    return l->totalAvailable() < r->totalAvailable();
            }
            else if (index["property"] == "runners_voidable") {
                if (desc)
                    return l->runnersVoidable() > r->runnersVoidable();
                else
                    return l->runnersVoidable() < r->runnersVoidable();
            }
            else if (index["property"] == "version") {
                if (desc)
                    return l->version() > r->version();
                else
                    return l->version() < r->version();
            }
        }
        return Sorter::compare(lhs, rhs);
    }

}