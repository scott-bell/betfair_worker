//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_CURRENTORDERSUMMARYREPORT_H
#define SXCLIENT_CURRENTORDERSUMMARYREPORT_H

#include <vector>
#include "CurrentOrderSummary.h"
namespace API {

    struct CurrentOrderSummaryReport {
        std::vector<CurrentOrderSummary> currentOrders;
        bool moreAvailable;


        CurrentOrderSummaryReport() = default; // TODO: Remove this
        explicit CurrentOrderSummaryReport(Json::Value json);

    };
}

#endif //SXCLIENT_CURRENTORDERSUMMARYREPORT_H
