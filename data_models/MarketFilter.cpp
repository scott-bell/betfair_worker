//
// Created by scott on 17/02/2020.
//

#include "MarketFilter.h"

namespace Data {

    MarketFilter::MarketFilter(Json::Value json) : Filter(json) {
    }

    bool MarketFilter::matches(const Data::DataObject &item) const {
        const Data::Market* i = (Data::Market*)(&item);
        for (const Json::Value &index : json()) {
            std::string op = index["operator"].asString();
            std::string val = index["value"].asString();
            std::string prop = index["property"].asString();

            if ((prop == "start_time") && (val != i->startTime())) { return false; }
            if ((prop == "name") && (val != i->name())) { return false; }
            if ((prop == "type") && (val != i->marketType())) { return false; }
            if ((prop == "exchange_id") && (val != i->exchangeId())) { return false; }
            if ((prop == "number_of_winners") && (std::stoi(val) != i->numberOfWinners())) { return false; }
            if ((prop == "event_id") && (val != i->parentEvent()->id())) { return false; }
            if ((prop == "event_name") && (val != i->parentEvent()->get_name())) { return false; }
            if ((prop == "race_id") && (val != i->parentRace()->id())) { return false; }
            if ((prop == "race_name") && (val != i->parentRace()->get_name())) { return false; }
            //if ((prop == "persistence_enabled") && (val != i->persistenceEnabled())) { return false; }
            //if ((prop == "suspend_time") && (val != i->persistenceEnabled())) { return false; }
            if ((prop == "suspend_time") && (val != i->suspendTime())) { return false; }
            if ((prop == "settle_time") && (val != i->settleTime())) { return false; }
            if ((prop == "status") && (val != i->status())) { return false; }
            if ((prop == "betting_type") && (val != i->bettingType())) { return false; }
            //if ((prop == "turn_in_play_enabled") && (val != i->turnInPlayEnabled())) { return false; }
            if ((prop == "regulator") && (val != i->regulator())) { return false; }
            //if ((prop == "market_base_rate") && (val != i->marketBaseRate())) { return false; }
            //discount_allowed
            if ((prop == "wallet") && (val != i->wallet())) { return false; }
            //if ((prop == "each_way_divisor") && (val != i->eachWayDivisor())) { return false; }
            if ((prop == "clarifications") && (val != i->clarifications())) { return false; }
            if ((prop == "race_type") && (val != i->raceType())) { return false; }
            //if ((prop == "is_market_data_delayed") && (val != i->is_market_data_delayed())) { return false; }
            if ((prop == "bet_delay") && (std::stoi(val) != i->betDelay())) { return false; }
            // bsp_reconciled
            // complete
            // inplay
            // etc.
        }
        return Filter::matches(item);
    }

}