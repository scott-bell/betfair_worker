//
// Created by scott on 18/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIROBJECT_H
#define BETFAIR_WORKER_BETFAIROBJECT_H


#include <string>

class BetfairObject {
protected:
    friend class BetfairData;
    std::string m_id;
    explicit BetfairObject(std::string id);
public:
    BetfairObject() = delete;
    const std::string& get_id() const;
};


#endif //BETFAIR_WORKER_BETFAIROBJECT_H
