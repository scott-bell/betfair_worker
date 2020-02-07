//
// Created by scott on 17/01/2020.
//

#include "BetfairData.h"
#include <utility>




DataModel<BetfairMarket>& BetfairData::marketModel() {
    return m_marketModel;
}
DataModel<BetfairEventType>& BetfairData::eventTypeModel() {
    return m_eventTypeModel;
}
DataModel<BetfairEvent>& BetfairData::eventModel() {
    return m_eventModel;
}
DataModel<BetfairGroup>& BetfairData::groupModel() {
    return m_groupModel;
}
DataModel<BetfairRunner>& BetfairData::runnerModel() {
    return m_runnerModel;
}
DataModel<BetfairRace>& BetfairData::raceModel() {
    return m_raceModel;
}


