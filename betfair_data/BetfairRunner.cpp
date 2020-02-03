//
// Created by scott on 03/02/2020.
//

#include "BetfairRunner.h"

BetfairRunner::BetfairRunner(std::string id, std::string name) :  BetfairObject(id), m_name(std::move(name)) {

}

Json::Value BetfairRunner::json() {
    Json::Value json;
    json["id"] = m_id;
    json["name"] = m_name;

    return json;
}
