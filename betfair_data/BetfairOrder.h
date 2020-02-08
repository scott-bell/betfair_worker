//
// Created by scott on 07/02/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRORDER_H
#define BETFAIR_WORKER_BETFAIRORDER_H


#include <string>
#include <optional>
#include "BetfairMarket.h"
#include "BetfairRunner.h"

class BetfairOrder : public BetfairObject {

    //std::string m_betId;
    BetfairMarket* m_market;
    BetfairRunner* m_runner;
    double m_handicap;
    double m_price;
    double m_size;
    double m_bspLiability;
    std::string m_side;
    std::string m_status;
    std::string m_persistenceType;
    std::string m_orderType;
    std::string m_placedDate;
    std::string m_matchedDate;
    double m_sizeMatched;
    double m_sizeRemaining;
    double m_sizeLapsed;
    double m_sizeCancelled;
    double m_sizeVoided;
    std::optional<std::string> m_regulatorAuthCode;
    std::optional<std::string> m_regulatorCode;
    std::optional<std::string> m_customerOrderRef;
    std::optional<std::string> m_customerStrategyRef;
public:
    Json::Value json();
    BetfairOrder (std::string id, BetfairMarket* market, BetfairRunner* runner, double handicap, double price,
                  double size, double bspLiability, std::string side, std::string status, std::string persistenceType,
                  std::string orderType, std::string placedDate, std::string matchedDate, double sizeMatched,
                  double sizeRemaining, double sizeLaped, double sizeCancelled, double sizeVoided,
                  std::optional<std::string> regulatorAuthCode, std::optional<std::string> regulatorCode,
                  std::optional<std::string> customOrderRef, std::optional<std::string> customerStrategyRef);

    void sizeRemaining(double size);
    void sizeMatched(double size);
    void sizeCancelled(double size);
    void sizeLapsed(double size);
    void sizeVoided(double size);
    void status(std::string status);
    void persistenceType(std::string s);

};


#endif //BETFAIR_WORKER_BETFAIRORDER_H
