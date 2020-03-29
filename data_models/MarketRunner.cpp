//
// Created by scott on 18/02/2020.
//

#include "MarketRunner.h"


namespace Data {
    Json::Value MarketRunner::json() const {
        Json::Value json;
        json["id"] = m_id;
        json["runner_id"] = m_runner.id();
        json["runner_name"] = m_runner.name();
        json["handicap"] = m_handicap;
        json["sort_priority"] = m_sortPriority;
        if (m_status.has_value())
            json["status"] = m_status.value();
        if (m_lastPriceTraded.has_value())
            json["last_price_traded"] = m_lastPriceTraded.value();
        if (m_totalMatched.has_value())
            json["total_matched"] = m_totalMatched.value();
        Json::Value backPrices = Json::arrayValue;
        for (auto i : m_backPrices) {
            Json::Value pz;
            pz["price"] = std::get<0>(i);
            pz["size"] = std::get<1>(i);
            backPrices.append(pz);
        }
        json["availability"]["back"] = backPrices;
        Json::Value layPrices = Json::arrayValue;
        for (auto i : m_layPrices) {
            Json::Value pz;
            pz["price"] = std::get<0>(i);
            pz["size"] = std::get<1>(i);
            layPrices.append(pz);
        }
        json["availability"]["lay"] = layPrices;
        Json::Value tradedPrices = Json::arrayValue;
        for (auto i : m_tradedPrices) {
            Json::Value pz;
            pz["price"] = std::get<0>(i);
            pz["size"] = std::get<1>(i);
            tradedPrices.append(pz);
        }
        json["traded"] = tradedPrices;
        return json;
    }

    MarketRunner::MarketRunner(std::string id, const Runner& runner, double handicap, int sortPriority):
            DataObject(std::move(id)), m_runner(runner), m_handicap(handicap), m_sortPriority(sortPriority) { }

    const Runner &MarketRunner::runner() const {
        return m_runner;
    }

    void MarketRunner::status(std::string status) {
        m_status = status;
    }
    void MarketRunner::lastPriceTraded(double d) {
        m_lastPriceTraded = d;
    }
    void MarketRunner::handicap(double d) {
        m_handicap = d;
    }
    void MarketRunner::adjustmentFactor(double d) {
        m_adjustmentFactor = d;
    }

    const std::optional<std::string>& MarketRunner::status() {
        return m_status;
    }
    void MarketRunner::totalMatched(double d) {
        m_totalMatched = d;
    }
    void MarketRunner::removalDate(const std::string &date) {
        m_removalDate = date;
    }
    void MarketRunner::backPrices(std::vector<std::tuple<double, double>>& prices) {
        m_backPrices = prices;
    }
    void MarketRunner::layPrices(std::vector<std::tuple<double, double>>& prices) {
        m_layPrices = prices;
    }
    void MarketRunner::tradedPrices(std::vector<std::tuple<double, double>>& prices) {
        m_tradedPrices = prices;
    }
}
