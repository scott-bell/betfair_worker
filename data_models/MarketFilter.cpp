//
// Created by scott on 17/02/2020.
//

#include "MarketFilter.h"

bool MarketFilter::match(const Data::Market &item) {
    return (!m_marketType.has_value()) || (item.marketType() == m_marketType);
}

MarketFilter::MarketFilter(Json::Value json) {
    if (json.isMember("type")) {
        m_marketType = json["type"].asString();
    }
}
