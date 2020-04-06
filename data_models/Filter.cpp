//
// Created by scott on 17/02/2020.
//

#include "Filter.h"

namespace Data {

    Filter::Filter(Json::Value json) : _json(std::move(json)) {
    }

    // [{"operator":"like","value":"MATCH_ODDS","property":"type"},{"operator":"like","value":"4","property":"number_of_winners"}]
    bool Filter::matches(const Data::DataObject& item) const {
        for (const Json::Value &index : json()) {
            std::string op = index["operator"].asString();
            std::string val = index["value"].asString();
            std::string prop = index["property"].asString();

            if (prop == "id") {
                if (val != item.id()) { return false; }
            }
        }
        return true;
    }

    const Json::Value &Filter::json() const {
        return _json;
    }


}