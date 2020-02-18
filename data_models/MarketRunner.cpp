//
// Created by scott on 18/02/2020.
//

#include "MarketRunner.h"


namespace Data {
    Json::Value MarketRunner::json() {
        Json::Value json;
        json["id"] = m_id;
        json["runner_id"] = m_runner.id();
        json["runner_name"] = m_runner.name();
        json["handicap"] = m_handicap;
        json["sort_priority"] = m_sortPriority;
        return json;
    }

    MarketRunner::MarketRunner(std::string id, const Runner& runner, double handicap, int sortPriority):
            DataObject(std::move(id)), m_runner(runner), m_handicap(handicap), m_sortPriority(sortPriority) { }

    const Runner &MarketRunner::runner() const {
        return m_runner;
    }
}
