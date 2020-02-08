//
// Created by scott on 17/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRDATA_H
#define BETFAIR_WORKER_BETFAIRDATA_H

#include <vector>
#include <betfair_data/BetfairMarket.h>
#include <betfair_data/BetfairEventType.h>
#include <betfair_data/BetfairRace.h>
#include <betfair_data/BetfairGroup.h>
#include <betfair_data/BetfairEvent.h>
#include <unordered_map>
#include <betfair_data/BetfairRunner.h>
#include <betfair_data/BetfairOrder.h>
#include "DataModel.h"


class BetfairData {
    bool m_verbose;
    DataModel<BetfairMarket>        m_marketModel = DataModel<BetfairMarket>{30000};
    DataModel<BetfairEventType>     m_eventTypeModel = DataModel<BetfairEventType>{100};
    DataModel<BetfairGroup>         m_groupModel = DataModel<BetfairGroup>{100};
    DataModel<BetfairRace>          m_raceModel = DataModel<BetfairRace>{1000};
    DataModel<BetfairEvent>         m_eventModel = DataModel<BetfairEvent>{5000};
    DataModel<BetfairRunner>        m_runnerModel = DataModel<BetfairRunner>{100000};
    DataModel<BetfairOrder>         m_orderModel = DataModel<BetfairOrder>{1000};
public:
    DataModel<BetfairMarket>& marketModel();
    DataModel<BetfairEventType>& eventTypeModel();
    DataModel<BetfairEvent>& eventModel();
    DataModel<BetfairGroup>& groupModel();
    DataModel<BetfairRunner>& runnerModel();
    DataModel<BetfairRace>& raceModel();
    DataModel<BetfairOrder>& orderModel();
    BetfairData(): m_verbose(false) {
    }

};

#endif //BETFAIR_WORKER_BETFAIRDATA_H