//
// Created by scott on 03/02/2020.
//

#include "Runner.h"

namespace Data {

    Runner::Runner(std::string id, std::string name) : DataObject(id), m_name(std::move(name)) {

    }

    Json::Value Runner::json() {
        Json::Value json;
        json["id"] = m_id;
        json["name"] = m_name;

        return json;
    }

}