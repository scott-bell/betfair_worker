//
// Created by scott on 18/02/2020.
//

#ifndef SX_CLIENT_MARKETRUNNER_H
#define SX_CLIENT_MARKETRUNNER_H


#include "Market.h"
#include "Runner.h"

namespace Data  {
    class MarketRunner : public DataObject {
        Runner m_runner;
        double m_handicap;
        int m_sortPriority;
    public:
        const Runner& runner() const;
        MarketRunner(std::string id, const Runner& runner, double handicap, int sortPriority);
        Json::Value json();
    };
}


#endif //SX_CLIENT_MARKETRUNNER_H
