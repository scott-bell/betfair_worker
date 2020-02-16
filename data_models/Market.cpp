//
// Created by scott on 16/01/2020.
//

#include "Market.h"

#include <utility>

namespace Data {

    Market::Market(std::string id, std::string exchange_id, std::string market_start_time,
                   std::string market_type, int number_of_winners, std::string name) :
            DataObject(std::move(id)),
            m_exchangeId(std::move(exchange_id)),
            m_startTime(std::move(market_start_time)),
            m_numberOfWinners(number_of_winners),
            m_name(std::move(name)),
            m_marketType(std::move(market_type)) {
    }

    Json::Value Market::json() {
        Json::Value json;
        json["id"] = m_id;
        json["start_time"] = m_startTime;
        json["name"] = m_name;
        json["type"] = m_marketType;
        json["exchange_id"] = m_exchangeId;
        json["number_of_winners"] = m_numberOfWinners;
        if (m_persistenceEnabled.has_value())
            json["persistence_enabled"] = m_persistenceEnabled.value();
        if (m_bspMarket.has_value())
            json["bsp_market"] = m_bspMarket.value();
        if (m_suspendTime.has_value())
            json["suspend_time"] = m_suspendTime.value();
        if (m_settleTime.has_value())
            json["settle_time"] = m_settleTime.value();
        if (m_status.has_value())
            json["status"] = m_status.value();
        if (m_bettingType.has_value())
            json["betting_type"] = m_bettingType.value();
        if (m_turnInPlayEnabled.has_value())
            json["turn_in_play_enabled"] = m_turnInPlayEnabled.value();
        json["market_type"] = m_marketType;
        if (m_regulator.has_value())
            json["regulator"] = m_regulator.value();
        if (m_marketBaseRate.has_value())
            json["market_nase_rate"] = m_marketBaseRate.value();
        if (m_discountAllowed.has_value())
            json["discount_allowed"] = m_discountAllowed.value();
        if (m_wallet.has_value())
            json["wallet"] = m_wallet.value();
        /*if (m_rules.has_value())
            json["rules"] = m_rules.value();
        if (m_rulesHasDate.has_value())
            json["rules_has_date"] = m_rulesHasDate.value();*/
        if (m_eachWayDivisor.has_value())
            json["each_way_divisor"] = m_eachWayDivisor.value();
        if (m_clarifications.has_value())
            json["clarifications"] = m_clarifications.value();
        if (m_raceType.has_value())
            json["race_type"] = m_raceType.value();
        if (m_isMarketDataDelayed.has_value())
            json["is_market_data_delayed"] = m_isMarketDataDelayed.value();
        if (m_betDelay.has_value())
            json["bet_delay"] = m_betDelay.value();
        if (m_bspReconciled.has_value())
            json["bsp_reconciled"] = m_bspReconciled.value();
        if (m_complete.has_value())
            json["complete"] = m_complete.value();
        if (m_inplay.has_value())
            json["inplay"] = m_inplay.value();
        if (m_numberOfRunners.has_value())
            json["number_of_runners"] = m_numberOfRunners.value();
        if (m_numberOfActiveRunners.has_value())
            json["number_of_active_runners"] = m_numberOfActiveRunners.value();
        if (m_lastMatchTime.has_value())
            json["last_match_time"] = m_lastMatchTime.value();
        if (m_totalMatched.has_value())
            json["total_matched"] = m_totalMatched.value();
        if (m_totalAvailable.has_value())
            json["total_available"] = m_totalAvailable.value();
        if (m_runnersVoidable.has_value())
            json["runners_voidable"] = m_runnersVoidable.value();
        if (m_version.has_value())
            json["version"] = std::to_string(m_version.value());

        return json;
    }

    void Market::status(const std::string &_status) {
        m_status = _status;
    }

    void Market::name(const std::string &_name) {
        m_name = _name;
    }

    void Market::persistenceEnabled(bool _persistenceEnabled) {
        m_persistenceEnabled = _persistenceEnabled;
    }

    void Market::bspMarket(bool _bspMarket) {
        m_bspMarket = _bspMarket;
    }

    void Market::suspendTime(const std::string &_suspendTime) {
        m_suspendTime = _suspendTime;
    }

    void Market::settleTime(const std::string &_settleTime) {
        m_settleTime = _settleTime;
    }

    void Market::bettingType(const std::string &_bettingType) {
        m_bettingType = _bettingType;
    }

    void Market::startTime(const std::string &_startTime) {
        m_startTime = _startTime;
    }

    const std::string &Market::name() const {
        return m_name;
    }

    const std::string &Market::startTime() const {
        return m_startTime;
    }

    const std::string &Market::exchangeId() const {
        return m_exchangeId;
    }

    const std::string &Market::marketType() const {
        return m_marketType;
    }

    int Market::numberOfWinners() const {
        return m_numberOfWinners;
    }

    void Market::turnInPlayEnabled(bool b) {
        m_turnInPlayEnabled = b;
    }

    void Market::marketType(const std::string &s) {
        m_marketType = s;

    }

    void Market::betDelay(int i) {
        m_betDelay = i;
    }

    void Market::bspReconciled(bool b) {
        m_bspReconciled = b;
    }

    void Market::complete(bool b) {
        m_complete = b;
    }

    void Market::inplay(bool b) {
        m_inplay = b;
    }

    void Market::numberOfRunners(int i) {
        m_numberOfRunners = i;
    }

    void Market::numberOfActiveRunners(int i) {
        m_numberOfActiveRunners = i;
    }

    void Market::lastMatchTime(const std::string &s) {
        m_lastMatchTime = s;
    }

    void Market::totalMatched(double d) {
        m_totalMatched = d;
    }

    void Market::totalAvailable(double d) {
        m_totalAvailable = d;
    }

    void Market::runnersVoidable(bool b) {
        m_runnersVoidable = b;
    }

    void Market::crossMatching(bool b) {
        m_crossMatching = b;
    }

    void Market::version(long l) {
        m_version = l;
    }

    void Market::exchangeId(std::string &val) {
        m_exchangeId = val;
    }

    void Market::numberOfWinners(int i) {
        m_numberOfWinners = i;

    }

    void Market::regulator(const std::string &s) {
        m_regulator = s;
    }

    void Market::marketBaseRate(double d) {
        m_marketBaseRate = d;
    }

    void Market::discountAllowed(bool b) {
        m_discountAllowed = b;
    }

    void Market::wallet(const std::string &s) {
        m_wallet = s;
    }

    void Market::rules(const std::string &s) {
        m_rules = s;
    }

    void Market::rulesHasDate(bool b) {
        m_rulesHasDate = b;
    }

    void Market::eachWayDivisor(double d) {
        m_eachWayDivisor = d;
    }

    void Market::clarifications(const std::string &s) {
        m_clarifications = s;
    }

    void Market::raceType(const std::string &s) {
        m_raceType = s;
    }

    void Market::isMarketDateDelayed(bool b) {
        m_isMarketDataDelayed = b;
    }

    std::optional<bool> Market::persistenceEnabled() const {
        return m_persistenceEnabled;
    }

    std::optional<bool> Market::bspMarket() const {
        return m_bspMarket;
    }

    const std::optional<std::string> &Market::suspendTime() const {
        return m_suspendTime;
    }

    const std::optional<std::string> &Market::settleTime() const {
        return m_settleTime;
    }

    const std::optional<std::string> &Market::bettingType() const {
        return m_bettingType;
    }

    std::optional<bool> Market::turnInPlayEnabled() const {
        return m_turnInPlayEnabled;
    }

    const std::optional<std::string> &Market::regulator() const {
        return m_regulator;
    }

    std::optional<double> Market::marketBaseRate() const {
        return m_marketBaseRate;
    }

    std::optional<bool> Market::discountAllowed() const {
        return m_discountAllowed;
    }

    const std::optional<std::string> &Market::wallet() const {
        return m_wallet;
    }

    const std::optional<std::string> &Market::rules() const {
        return m_rules;
    }

    const std::optional<std::string> &Market::status() const {
        return m_status;
    }

}
