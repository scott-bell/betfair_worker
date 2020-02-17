//
// Created by scott on 07/02/2020.
//

#ifndef SXCLIENT_DATA_ORDER_H
#define SXCLIENT_DATA_ORDER_H


#include <string>
#include <optional>
#include "Market.h"
#include "Runner.h"
namespace Data {
    class Order : public DataObject {
        Market *m_market;
        Runner *m_runner;
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

        Order(std::string id, Market *market, Runner *runner, double handicap, double price,
              double size, double bspLiability, std::string side, std::string status,
              std::string persistenceType,
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

}
#endif //SXCLIENT_DATA_ORDER_H
