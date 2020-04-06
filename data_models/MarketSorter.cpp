//
// Created by scott on 30/03/2020.
//

#include "MarketSorter.h"

#include <utility>
#include "Market.h"

namespace Data {

    MarketSorter::MarketSorter(Json::Value json) : Sorter(std::move(json)) {
    }

    bool MarketSorter::compareProperties(const Data::Market* l, const Data::Market* r, bool& success, std::string& prop, bool desc) const {
        success = true;
        if (prop == "name") {
            if (l->name() > r->name()) {
                return desc;
            } else if (l->name() < r->name()) {
                return !desc;
            }
        }
        else if (prop == "start_time") {
            if (l->startTime() > r->startTime()) {
                return desc;
            } else if (l->startTime() < r->startTime()) {
                return !desc;
            }
        }
        else if (prop == "type") {
            if (l->marketType() > r->marketType()) {
                return desc;
            } else if (l->marketType() < r->marketType()) {
                return !desc;
            }
        }
        else if (prop == "number_of_winners") {
            if (l->numberOfWinners() > r->numberOfWinners()) {
                return desc;
            } else if (l->numberOfWinners() < r->numberOfWinners()) {
                return !desc;
            }
        }
        else if (prop == "exchange_id") {
            if (l->exchangeId() > r->exchangeId()) {
                return desc;
            } else if (l->exchangeId() < r->exchangeId()) {
                return !desc;
            }
        }
        else if ((prop == "event_id") && (l->parentEvent() != nullptr) && (r->parentEvent() != nullptr)) {
            if (l->parentEvent()->id() > r->parentEvent()->id()) {
                return desc;
            } else if (l->parentEvent()->id() < r->parentEvent()->id()) {
                return !desc;
            }
        }
        else if ((prop == "event_name") && (l->parentEvent() != nullptr) && (r->parentEvent() != nullptr)) {
            if (l->parentEvent()->get_name() > r->parentEvent()->get_name()) {
                return desc;
            } else if (l->parentEvent()->get_name() < r->parentEvent()->get_name()) {
                return !desc;
            }
        }
        else if ((prop == "race_id" ) && (l->parentRace() != nullptr) && (r->parentRace() != nullptr)) {
            if (l->parentRace()->id() > r->parentRace()->id()) {
                return desc;
            } else if (l->parentRace()->id() < r->parentRace()->id()) {
                return !desc;
            }
        }
        else if ((prop == "race_name") && (l->parentRace() != nullptr) && (r->parentRace() != nullptr)) {
            if (l->parentRace()->get_name() > r->parentRace()->get_name()) {
                return desc;
            } else if (l->parentRace()->get_name() < r->parentRace()->get_name()) {
                return !desc;
            }
        }
        else if (prop == "persistence_enabled") {
            if (l->persistenceEnabled() > r->persistenceEnabled()) {
                return desc;
            } else if (l->persistenceEnabled() < r->persistenceEnabled()) {
                return !desc;
            }
        }
        else if (prop == "bsp_market") {
            if (l->bspMarket() > r->bspMarket()) {
                return desc;
            } else if (l->bspMarket() < r->bspMarket()) {
                return !desc;
            }
        }
        else if (prop == "suspend_time") {
            if (l->suspendTime() > r->suspendTime()) {
                return desc;
            } else if (l->suspendTime() < r->suspendTime()) {
                return !desc;
            }
        }
        else if (prop == "settle_time") {
            if (l->settleTime() > r->settleTime()) {
                return desc;
            } else if (l->settleTime() < r->settleTime()) {
                return !desc;
            }
        }
        else if (prop == "status") {
            if (l->status() > r->status()) {
                return desc;
            } else if (l->status() < r->status()) {
                return !desc;
            }
        }
        else if (prop == "betting_type") {
            if (l->bettingType() > r->bettingType()) {
                return desc;
            } else if (l->bettingType() < r->bettingType()) {
                return !desc;
            }
        }
        else if (prop == "turn_in_play_enabled") {
            if (l->turnInPlayEnabled() > r->turnInPlayEnabled()) {
                return desc;
            } else if (l->turnInPlayEnabled() < r->turnInPlayEnabled()) {
                return !desc;
            }
        }
        else if (prop == "regulator") {
            if (l->regulator() > r->regulator()) {
                return desc;
            } else if (l->regulator() < r->regulator()) {
                return !desc;
            }
        }
        else if (prop == "market_base_rate") {
            if (l->marketBaseRate() > r->marketBaseRate()) {
                return desc;
            } else if (l->marketBaseRate() < r->marketBaseRate()) {
                return !desc;
            }
        }
        else if (prop == "discount_allowed") {
            if (l->discountAllowed() > r->discountAllowed()) {
                return desc;
            } else if (l->discountAllowed() < r->discountAllowed()) {
                return !desc;
            }
        }
        else if (prop == "wallet") {
            if (l->wallet() > r->wallet()) {
                return desc;
            } else if (l->wallet() < r->wallet()) {
                return !desc;
            }
        }
        else if (prop == "each_way_divisor") {
            if (l->eachWayDivisor() > r->eachWayDivisor()) {
                return desc;
            } else if (l->eachWayDivisor() < r->eachWayDivisor()) {
                return !desc;
            }
        }
        else if (prop == "clarifications") {
            if (l->clarifications() > r->clarifications()) {
                return desc;
            } else if (l->clarifications() < r->clarifications()) {
                return !desc;
            }
        }
        else if (prop == "race_type") {
            if (l->raceType() > r->raceType()) {
                return desc;
            } else if (l->raceType() < r->raceType()) {
                return !desc;
            }
        }
        else if (prop == "is_market_data_delayed") {
            if (l->isMarketDataDelayed() > r->isMarketDataDelayed()) {
                return desc;
            } else if (l->isMarketDataDelayed() < r->isMarketDataDelayed()) {
                return !desc;
            }
        }
        else if (prop == "bet_delay") {
            if (l->betDelay() > r->betDelay()) {
                return desc;
            } else if (l->betDelay() < r->betDelay()) {
                return !desc;
            }
        }
        else if (prop == "bsp_reconciled") {
            if (l->bspReconciled() > r->bspReconciled()) {
                return desc;
            } else if (l->bspReconciled() < r->bspReconciled()) {
                return !desc;
            }
        }
        else if (prop == "complete") {
            if (l->complete() > r->complete()) {
                return desc;
            } else if (l->complete() < r->complete()) {
                return !desc;
            }
        }
        else if (prop == "inplay") {
            if (l->inplay() > r->inplay()) {
                return desc;
            } else if (l->inplay() < r->inplay()) {
                return !desc;
            }
        }
        else if (prop == "number_of_runners") {
            if (l->numberOfRunners() > r->numberOfRunners()) {
                return desc;
            } else if (l->numberOfRunners() < r->numberOfRunners()) {
                return !desc;
            }
        }
        else if (prop == "number_of_active_runners") {
            if (l->numberOfActiveRunners() > r->numberOfActiveRunners()) {
                return desc;
            } else if (l->numberOfActiveRunners() < r->numberOfActiveRunners()) {
                return !desc;
            }
        }
        else if (prop == "last_match_time") {
            if (l->lastMatchTime() > r->lastMatchTime()) {
                return desc;
            } else if (l->lastMatchTime() < r->lastMatchTime()) {
                return !desc;
            }
        }
        else if (prop == "total_matched") {
            if (l->totalMatched() > r->totalMatched()) {
                return desc;
            } else if (l->totalMatched() < r->totalMatched()) {
                return !desc;
            }
        }
        else if (prop == "total_available") {
            if (l->totalAvailable() > r->totalAvailable()) {
                return desc;
            } else if (l->totalAvailable() < r->totalAvailable()) {
                return !desc;
            }
        }
        else if (prop == "runners_voidable") {
            if (l->runnersVoidable() > r->runnersVoidable()) {
                return desc;
            } else if (l->runnersVoidable() < r->runnersVoidable()) {
                return !desc;
            }
        }
        else if (prop == "version") {
            if (l->version() > r->version()) {
                return desc;
            } else if (l->version() < r->version()) {
                return !desc;
            }
        }
        return Sorter::compareProperties(l, r, success, prop, desc);
    }

    bool MarketSorter::compare(const DataObject &lhs, const DataObject &rhs) const {
        const Data::Market* l = (Data::Market*)(&lhs);
        const Data::Market* r = (Data::Market*)(&rhs);

        for (const Json::Value &index : json()) {
            bool success = true;
            std::string property = index["property"].asString();
            bool desc = index["direction"].asString() == "DESC";

            bool result = compareProperties(l, r, success, property, desc);
            if (success) {
                return result;
            }
        }
        return lhs.id() < rhs.id();
    }
}