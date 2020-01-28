//
// Created by scott on 24/01/2020.
//

#ifndef BETFAIR_WORKER_CURRENTORDERSUMMARYREPORT_H
#define BETFAIR_WORKER_CURRENTORDERSUMMARYREPORT_H

#include <vector>
#include "CurrentOrderSummary.h"

struct CurrentOrderSummaryReport {
    std::vector<CurrentOrderSummary> currentOrders;
    bool moreAvailable;


    CurrentOrderSummaryReport() = default; // TODO: Remove this
    explicit CurrentOrderSummaryReport(Json::Value json);

};


#endif //BETFAIR_WORKER_CURRENTORDERSUMMARYREPORT_H
