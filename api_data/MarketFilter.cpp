//
// Created by scott on 21/01/2020.
//

#include "MarketFilter.h"

namespace API {

    Json::Value MarketFilter::setToJson(std::set<std::string> items) const {
        Json::Value nested;
        for (const auto &s : items) {
            nested.append(s);
        }
        return nested;
    }

    Json::Value MarketFilter::json() const {
        Json::Value json;
        if (m_eventTypeIds.has_value())
            json["eventTypeIds"] = setToJson(m_eventTypeIds.value());
        if (m_eventIds.has_value())
            json["eventIds"] = setToJson(m_eventIds.value());
        if (m_competitionIds.has_value())
            json["competitionIds"] = setToJson(m_competitionIds.value());
        if (m_marketIds.has_value())
            json["marketIds"] = setToJson(m_marketIds.value());
        if (m_venues.has_value())
            json["venues"] = setToJson(m_venues.value());
        if (m_bspOnly.has_value())
            json["bspOnly"] = m_bspOnly.value();
        if (m_turnInPlayEnabled.has_value())
            json["turnInPlayEnabled"] = m_turnInPlayEnabled.value();
        if (m_inPlayOnly.has_value())
            json["inPlayOnly"] = m_inPlayOnly.value();
        if (m_marketBettingTypes.has_value())
            json["marketBettingTypes"] = setToJson(m_marketBettingTypes.value());
        if (m_marketCountries.has_value())
            json["marketCountries"] = setToJson(m_marketCountries.value());
        if (m_marketTypeCodes.has_value())
            json["marketTypeCodes"] = setToJson(m_marketTypeCodes.value());
        if (m_withOrders.has_value())
            json["withOrders"] = setToJson(m_withOrders.value());
        if (m_raceTypes.has_value())
            json["raceTypes"] = setToJson(m_raceTypes.value());

        return json;
    }

    MarketFilter::MarketFilter(const std::set<std::string> &marketIds) : m_marketIds(marketIds) {

    }

    MarketFilter::MarketFilter() {

    }
}