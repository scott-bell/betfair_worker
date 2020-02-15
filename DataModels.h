//
// Created by scott on 17/01/2020.
//

#ifndef SXCLIENT_DATAMODELS_H
#define SXCLIENT_DATAMODELS_H

#include <vector>
#include <data_models/Market.h>
#include <data_models/EventType.h>
#include <data_models/Race.h>
#include <data_models/Group.h>
#include <data_models/Event.h>
#include <unordered_map>
#include <data_models/Runner.h>
#include <data_models/Order.h>
#include "DataModel.h"


class DataModels {
    bool m_verbose;
    DataModel<Data::Market>        m_marketModel = DataModel<Data::Market>{30000};
    DataModel<Data::EventType>     m_eventTypeModel = DataModel<Data::EventType>{100};
    DataModel<Data::Group>         m_groupModel = DataModel<Data::Group>{100};
    DataModel<Data::Race>          m_raceModel = DataModel<Data::Race>{1000};
    DataModel<Data::Event>         m_eventModel = DataModel<Data::Event>{5000};
    DataModel<Data::Runner>        m_runnerModel = DataModel<Data::Runner>{100000};
    DataModel<Data::Order>         m_orderModel = DataModel<Data::Order>{1000};
public:
    DataModel<Data::Market>& marketModel();
    DataModel<Data::EventType>& eventTypeModel();
    DataModel<Data::Event>& eventModel();
    DataModel<Data::Group>& groupModel();
    DataModel<Data::Runner>& runnerModel();
    DataModel<Data::Race>& raceModel();
    DataModel<Data::Order>& orderModel();
    DataModels(): m_verbose(false) {
    }

};

#endif //SXCLIENT_DATAMODELS_H