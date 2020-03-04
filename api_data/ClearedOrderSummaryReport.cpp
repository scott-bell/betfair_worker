//
// Created by scott on 03/03/2020.
//

#include "ClearedOrderSummaryReport.h"

namespace API {

    ClearedOrderSummaryReport::ClearedOrderSummaryReport(Json::Value json)
    {
        {
            const Json::Value result = json["currentOrders"];
            std::vector<ClearedOrderSummary> v;
            for (const auto &index : result) {
                v.emplace_back(ClearedOrderSummary(index));
            }
            clearedOrders = v;
        }
        moreAvailable = json["moreAvailable"].asBool();

    }
}