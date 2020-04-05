//
// Created by scott on 29/03/2020.
//

#include "Sorter.h"

namespace Data {

    Sorter::Sorter(Json::Value json) : json(std::move(json)){

    }

    bool Sorter::compare(const DataObject &lhs, const DataObject &rhs) const {
        for (const Json::Value &index : json) {
            bool success = true;
            std::string property = index["property"].asString();
            bool desc = index["direction"].asString() == "DESC";

            bool result = compareProperties(&lhs, &rhs, success, property, desc);
            if (success) {
                return result;
            }
        }
        return lhs.id() < rhs.id();
    }

    bool Sorter::compareProperties(const Data::DataObject *l, const Data::DataObject *r, bool& success, std::string& prop, bool desc) const {
        if (prop == "id") {
            if (l->id() > r->id()) {
                return desc;
            } else if (l->id() < r->id()) {
                return !desc;
            }
        }
        success = false;
        return false;
    }

}