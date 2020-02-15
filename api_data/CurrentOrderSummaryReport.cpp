//
// Created by scott on 24/01/2020.
//

#include "CurrentOrderSummaryReport.h"
namespace API {

    CurrentOrderSummaryReport::CurrentOrderSummaryReport(Json::Value json) {
        {
            const Json::Value result = json["currentOrders"];
            std::vector<CurrentOrderSummary> v;
            for (const auto &index : result) {
                v.emplace_back(CurrentOrderSummary(index));
            }
            currentOrders = v;
        }
        moreAvailable = json["moreAvailable"].asBool();

    }
}