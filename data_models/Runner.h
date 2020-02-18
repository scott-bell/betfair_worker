//
// Created by scott on 03/02/2020.
//

#ifndef SXCLIENT_DATA_RUNNER_H
#define SXCLIENT_DATA_RUNNER_H


#include <jsoncpp/json/json.h>
#include "DataObject.h"
namespace Data {

class Runner  : public DataObject {
    std::string m_name;
public:
    Json::Value json();
    Runner(std::string id, std::string name);
    const std::string& name();
    bool operator < (const Runner& rhs) const {
        return id() < rhs.id();
    }
    bool operator == (const Runner& rhs) const {
        return id() == rhs.id();
    }
};

}

#endif //SXCLIENT_DATA_RUNNER_H
