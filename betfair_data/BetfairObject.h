//
// Created by scott on 18/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIROBJECT_H
#define BETFAIR_WORKER_BETFAIROBJECT_H


#include <string>
#include <jsoncpp/json/json.h>

class BetfairObject {
protected:
    friend class BetfairData;
    std::string m_id;
    explicit BetfairObject(std::string id);
public:
    BetfairObject() = delete;
    virtual Json::Value json() = 0;
    [[nodiscard]] const std::string& get_id() const;
};


#endif //BETFAIR_WORKER_BETFAIROBJECT_H
