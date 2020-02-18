//
// Created by scott on 17/01/2020.
//

#include "DataModels.h"
#include <utility>




DataModel<Data::Market>& DataModels::marketModel() {
    return m_marketModel;
}
DataModel<Data::EventType>& DataModels::eventTypeModel() {
    return m_eventTypeModel;
}
DataModel<Data::Event>& DataModels::eventModel() {
    return m_eventModel;
}
DataModel<Data::Group>& DataModels::groupModel() {
    return m_groupModel;
}
DataModel<Data::Runner>& DataModels::runnerModel() {
    return m_runnerModel;
}
DataModel<Data::Race>& DataModels::raceModel() {
    return m_raceModel;
}

DataModel<Data::Order>& DataModels::orderModel() {
    return m_orderModel;
}

DataModel<Data::MarketRunner> &DataModels::marketRunnerModel() {
    return m_marketRunnerModel;
}


