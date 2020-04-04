//
// Created by scott on 16/01/2020.
//

#ifndef SXCLIENT_MARKET_H
#define SXCLIENT_MARKET_H


#include <string>
#include <optional>
#include <jsoncpp/json/json.h>
#include "DataObject.h"
#include "Filter.h"
#include "MarketRunner.h"
#include "Runner.h"
#include "Event.h"
#include "Race.h"

namespace Data {

    class MarketRunner;
    class Event;
    class Race;

    class Market : public DataObject {

        Event* m_parentEvent;
        Race* m_parentRace;

        //                                                                   MarketBook      MarketCatalogue
        std::string m_exchangeId;                                      //
        std::string m_startTime;                                        //       X                  X
        int m_numberOfWinners;                                          //       X
        std::string m_name;                         //                          X
        std::optional<bool> m_persistenceEnabled;           //                          X
        std::optional<bool> m_bspMarket;                    //                          X
        std::optional<std::string> m_suspendTime;                  //                          X
        std::optional<std::string> m_settleTime;                   //                          X
        std::optional<std::string> m_bettingType;                  //                          X
        std::optional<bool> m_turnInPlayEnabled;            //                          X
        std::string m_marketType;                   //                          X
        std::optional<std::string> m_regulator;                    //                          X
        std::optional<double> m_marketBaseRate;               //                          X
        std::optional<bool> m_discountAllowed;              //                          X
        std::optional<std::string> m_wallet;                       //                          X
        std::optional<std::string> m_rules;                        //                          X
        std::optional<bool> m_rulesHasDate;                 //                          X
        std::optional<double> m_eachWayDivisor;               //                          X
        std::optional<std::string> m_clarifications;               //                          X
        std::optional<std::string> m_raceType;                     //                          X
        std::optional<bool> m_isMarketDataDelayed;          //      X
        std::optional<std::string> m_status;                       //      X
        std::optional<int> m_betDelay;                     //      X
        std::optional<bool> m_bspReconciled;                //      X
        std::optional<bool> m_complete;                     //      X
        std::optional<bool> m_inplay;                       //      X
        std::optional<int> m_numberOfRunners;              //      X
        std::optional<int> m_numberOfActiveRunners;        //      X
        std::optional<std::string> m_lastMatchTime;                //      X
        std::optional<double> m_totalMatched;                 //      X                   X
        std::optional<double> m_totalAvailable;               //      X
        std::optional<bool> m_runnersVoidable;              //      X
        std::optional<bool> m_crossMatching;                //      X
        std::optional<long> m_version;                      //      X

        //MarketBettingType m_bettingType; // TODO
        //MarketLineRangeInfo m_lineRangeInfo; // TODO
        //PriceLadderDescription m_PriceLadderDescription; // TODO

        std::vector<MarketRunner*> m_marketRunners;

    public:
        Market(std::string id, std::string exchange_id, std::string market_start_time,
               std::string market_type, int number_of_winners, std::string name, Race* race);
        Market(std::string id, std::string exchange_id, std::string market_start_time,
               std::string market_type, int number_of_winners, std::string name, Event* event);

        Market() = delete;

        void addMarketRunner(MarketRunner *marketRunner);

        void parentRace(Race* race);
        void parentEvent(Event* event);

        Json::Value json() const;
        void exchangeId(std::string &s);
        void startTime(const std::string &_startTime);
        void numberOfWinners(int i);
        void name(const std::string &name);
        void persistenceEnabled(bool _persistenceEnabled);
        void bspMarket(bool _bspMarket);
        void suspendTime(const std::string &_suspendTime);
        void settleTime(const std::string &_settleTime);
        void bettingType(const std::string &_bettingType);
        void turnInPlayEnabled(bool b);
        void marketType(const std::string &s);
        void regulator(const std::string &s);
        void marketBaseRate(double d);
        void discountAllowed(bool b);
        void wallet(const std::string &s);
        void rules(const std::string &s);
        void rulesHasDate(bool b);
        void eachWayDivisor(double d);
        void clarifications(const std::string &s);
        void raceType(const std::string &s);
        void isMarketDateDelayed(bool b);
        void status(const std::string &status);
        void betDelay(int i);
        void bspReconciled(bool b);
        void complete(bool b);
        void inplay(bool b);
        void numberOfRunners(int i);
        void numberOfActiveRunners(int i);
        void lastMatchTime(const std::string &s);
        void totalMatched(double d);
        void totalAvailable(double d);
        void crossMatching(bool b);
        void runnersVoidable(bool b);
        void version(long l);
        Event* parentEvent() const;
        Race* parentRace() const;
        [[nodiscard]] const std::string &exchangeId() const;
        [[nodiscard]] const std::string &startTime() const;
        [[nodiscard]] int numberOfWinners() const;
        [[nodiscard]] const std::string &name() const;
        [[nodiscard]] std::optional<bool> persistenceEnabled() const;
        [[nodiscard]] std::optional<bool> bspMarket() const;
        [[nodiscard]] const std::optional<std::string> &suspendTime() const;
        [[nodiscard]] const std::optional<std::string> &settleTime() const;
        [[nodiscard]] const std::optional<std::string> &bettingType() const;
        [[nodiscard]] std::optional<bool> turnInPlayEnabled() const;
        [[nodiscard]] const std::string &marketType() const;
        [[nodiscard]] const std::optional<std::string> &regulator() const;
        [[nodiscard]] std::optional<double> marketBaseRate() const;
        [[nodiscard]] std::optional<bool> discountAllowed() const;
        [[nodiscard]] const std::optional<std::string> &wallet() const;
        [[nodiscard]] const std::optional<std::string> &rules() const;
        [[nodiscard]] std::optional<bool> rulesHasDate() const;
        [[nodiscard]] std::optional<double> eachWayDivisor() const;
        [[nodiscard]] const std::optional<std::string> &clarifications() const;
        [[nodiscard]] const std::optional<std::string> &raceType() const;
        [[nodiscard]] std::optional<bool> isMarketDataDelayed() const;
        [[nodiscard]] const std::optional<std::string> &status() const;
        [[nodiscard]] std::optional<int> betDelay() const;
        [[nodiscard]] std::optional<bool> bspReconciled() const;
        [[nodiscard]] std::optional<bool> complete() const;
        [[nodiscard]] std::optional<bool> inplay() const;
        [[nodiscard]] std::optional<int> numberOfRunners() const;
        [[nodiscard]] std::optional<int> numberOfActiveRunners() const;
        [[nodiscard]] const std::optional<std::string> &lastMatchTime() const;
        [[nodiscard]] std::optional<double> totalMatched() const;
        [[nodiscard]] std::optional<double> totalAvailable() const;
        [[nodiscard]] std::optional<bool> runnersVoidable() const;
        [[nodiscard]] std::optional<long> version() const;

    };
}
#endif //SXCLIENT_MARKET_H
