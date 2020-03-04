//
// Created by scott on 03/03/2020.
//

#ifndef SX_CLIENT_CLEAREDORDERSUMMARYREPORT_H
#define SX_CLIENT_CLEAREDORDERSUMMARYREPORT_H


#include <vector>
#include <jsoncpp/json/value.h>
#include "ClearedOrderSummary.h"

namespace API {

    struct ClearedOrderSummaryReport {
        std::vector<ClearedOrderSummary> clearedOrders;
        bool moreAvailable;

        ClearedOrderSummaryReport() = default; // TODO: Remove this
        explicit ClearedOrderSummaryReport(Json::Value json);

    };
}

#endif //SX_CLIENT_CLEAREDORDERSUMMARYREPORT_H
