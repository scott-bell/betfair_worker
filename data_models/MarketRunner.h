//
// Created by scott on 18/02/2020.
//

#ifndef SX_CLIENT_MARKETRUNNER_H
#define SX_CLIENT_MARKETRUNNER_H


#include "Market.h"
#include "Runner.h"

namespace Data  {
    class MarketRunner : public DataObject {
        const Runner& m_runner;
        double m_handicap;
        int m_sortPriority;
        std::optional<std::string> m_status;
        std::optional<double> m_lastPriceTraded;
        std::optional<double> m_adjustmentFactor;
        std::optional<double> m_totalMatched;
        std::optional<std::string> m_removalDate;
        std::vector<std::tuple<double,double>> m_backPrices;
        std::vector<std::tuple<double,double>> m_layPrices;
        std::vector<std::tuple<double,double>> m_tradedPrices;

    public:
        const Runner& runner() const;
        void status(std::string status);
        void lastPriceTraded(double d);
        void handicap(double d);
        void totalMatched(double d);
        void removalDate(const std::string& date);
        void adjustmentFactor(double d);
        void backPrices(std::vector<std::tuple<double,double>>& prices);
        void layPrices(std::vector<std::tuple<double,double>>& prices);
        void tradedPrices(std::vector<std::tuple<double,double>>& prices);
        const std::optional<std::string>& status();
        MarketRunner(std::string id, const Runner& runner, double handicap, int sortPriority);
        Json::Value json() const;
    };
}


#endif //SX_CLIENT_MARKETRUNNER_H
